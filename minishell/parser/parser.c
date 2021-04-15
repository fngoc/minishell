#include "../minishell.h"

/*
** checks: проверки.
*/

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

/*
** free_read_line_exit: очистка после парсинга строки.
*/

static void		free_read_line_exit(t_parser *p)
{
	free(p->buf);
	free(p->str);
	free_map(p->map_history);
	ft_putendl_fd("exit", 1);
}

/*
** read_line: чтение линии.
*/

static	void	read_line(int fd, t_parser *p)
{
	while (p->buf == NULL || ft_strcmp(p->buf, "\4"))
	{
		t_file file;
		dup2(1, STDIN_FILENO);
		dup2(0, STDOUT_FILENO);
		if (p->buf != NULL)
			free(p->buf);
		if (!(p->buf = ft_calloc(2, sizeof(char))))
			error("Allocated error", 11);
		tputs(save_cursor, 1, &ft_putchar);
		write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		while (((p->len_str = read(0, p->buf, 100)) != -1) &&
		ft_strcmp(p->buf, "\n") && ft_strcmp(p->buf, "\4"))
		{
			p->backspace = 0;
			p->buf = check_buffer(p);
			if (p->buf == NULL)
				break ;
			checks(p);
		}
		write(1, "\n", 1);
		p->step_history = p->len_map;
		set_line(p->str, fd, p);
		privacy_check(p->str, p);
		if (ft_strlen(p->str) > 0)
			parser_commands(p->str, p, &file);
		p->flag_folder = 0;
		p->redir_here = 0;
		p->flag_redir = 0;
		ft_bzero(p->str, ft_strlen(p->str));
	}
	free_read_line_exit(p);
}

/*
** init_parser: начальные значения структуры парсера.
*/

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
}

/*
** parser: запуск парсера.
*/

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
