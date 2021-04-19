#include "../minishell.h"

static	void	checks(t_parser *p)
{
	char	*tmp_p_str;

	if (!is_arrow(p->buf))
	{
		tmp_p_str = NULL;
		tmp_p_str = ft_strjoin(p->str, p->buf);
		free(p->str);
		p->str = tmp_p_str;
	}
	if (p->backspace)
		p->str = delet_last_char(p->str, 1);
}

static void		free_read_line_exit(t_parser *p)
{
	free(p->buf);
	free(p->str);
	free_map(p->map_history);
	ft_putendl_fd("exit", 1);
}

static	void	read_line(int fd, t_parser *p)
{
	t_file file;

	while (p->buf == NULL || ft_strcmp(p->buf, "\4"))
	{
		fd_check(&file);
		if (p->buf != NULL)
			free(p->buf);
		if (!(p->buf = ft_calloc(2, sizeof(char))))
			error("Allocated error", 11);
		tputs(save_cursor, 1, &ft_putchar);
		write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		while (((p->len_str = read(STDOUT_FILENO, p->buf, 100)) != -1) &&
		ft_strcmp(p->buf, "\n") && ft_strcmp(p->buf, "\4"))
		{
			p->backspace = 0;
			p->buf = check_buffer(p);
			if (p->buf == NULL)
				break ;
			checks(p);
		}
		after_reading_line(p, fd, &file);
	}
	free_read_line_exit(p);
}

static	void	init_parser(t_parser *p)
{
	p->step_history = -1;
	p->len_map = -1;
	if (!(p->map_history = ft_calloc(500, sizeof(char *))))
		error("Allocated error", 11);
	if (!(p->str = ft_calloc(2, sizeof(char))))
		error("Allocated error", 11);
	p->buf = NULL;
	p->flag_echo_n = 0;
	p->flag_quotation_mark = 0;
	p->flag_redir = 0;
	p->flag_folder = 0;
	p->redir_here = 0;
	p->flag_please = 0;
	p->flag_please_1 = 0;
}

void			parser(void)
{
	int				fd;
	t_parser		p;
	struct termios	term;

	signal(SIGQUIT, ft_quit);
	signal(SIGINT, ft_sigint);
	term = init();
	fd = make_file();
	init_parser(&p);
	read_line(fd, &p);
	term.c_lflag |= ~(ECHO);
	term.c_lflag |= ~(ICANON);
}
