#include "parser.h"
#include "../libft/libft.h"
#include "../logic/logic.h"

int	ft_istab(char line)
{
	if (line == ' ')
		return (1);
	return (0);
}

void chek_pwd(char *line)
{
	++line;
	if (*line == 'w' || *line == 'W')
	{
		++line;
		if ((*line == 'd' || *line == 'D'))
		{
			++line;
			if (*line == ' ' || *line == '\n' || *line == '\0')
			{
				print_pwd();
				write(1, "\n", 1);
			}
		}
		else
			return ;
	}
	 else
	 	return ;
}

void	check_command(char *line, int size)
{
	(void)size;

	while (*line != '\0')
	{
		if (ft_istab(*line))
			++line;
		else if (*line == 'p' || *line == 'P')
		{
			chek_pwd(line);
		}
		// else
		// {
		// 	write(1, "minishell: ", 11);
		// 	write(1, line, ft_strlen(line));
		// 	ft_putstr_fd(": command not found\n", 1);
		// }
		++line;
	}
}

/*
** get_history_previous: взять предыдущую историю.
*/

void get_history_previous(t_parser *p)
{
	ft_bzero(p->str, ft_strlen(p->str));
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map[p->step_history]);
	// if (p->flag_step_history_previou == 0)
	// {
		--p->step_history;
	// 	p->flag_step_history_previou = 0;
	// 	p->flag_step_history_next = 1;
	// }
	// else
	// {
	// 	p->step_history -= 2;
	// 	p->flag_step_history_previou = 0;
	// }
	write(1, p->str, ft_strlen(p->str));
}

/*
** get_history_next: взять следующую историю.
*/

void get_history_next(t_parser *p)
{
	ft_bzero(p->str, ft_strlen(p->str));
	// if (p->flag_step_history_next == 0)
	// {
		++p->step_history;
	// 	p->flag_step_history_previou = 1;
	// 	p->flag_step_history_next = 0;
	// }
	// else
	// {
	// 	p->step_history += 2;
	// 	p->flag_step_history_next = 0;
	// }
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map[p->step_history]);
	write(1, p->str, ft_strlen(p->str));
}

/*
** get_line: считываем линию.
*/

char	*get_line(t_parser *p)
{
	p->buf[p->len] = 0;
	if (!ft_strcmp(p->buf, "\e[A")) //стрелочка вверх
	{
		if (p->step_history >= 0)
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "\033[0;35m$minishell: \033[0m", 23);
			get_history_previous(p);
		}
	}
	else if (!ft_strcmp(p->buf, "\e[B")) //стрелочка вниз
	{
		if (p->step_history < p->len_map)
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "\033[0;35m$minishell: \033[0m", 23);
			get_history_next(p);
		}
		else if (p->step_history >= p->len_map)
		{
			ft_bzero(p->str, ft_strlen(p->str));
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "\033[0;35m$minishell: \033[0m", 23);
		}
	}
	else if (!ft_strcmp(p->buf, "\177")) //клавиша backspase
	{
		if (ft_strlen(p->str) != 0)
		{
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", 0), 1, ft_putchar);
			write(1, p->buf, p->len);
			++p->backspace;
		}
	}
	else if (!ft_strcmp(p->buf, "\t"))
	{
		ft_bzero(p->str, ft_strlen(p->str));
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		return ("\0");
	}
	else if (!ft_strcmp(p->buf, "\e[C") || !ft_strcmp(p->buf, "\e[D")) //замена клавишь влево и вправо
		return (p->buf);
	else // печать символа
	{
		if (!ft_strcmp(p->buf, "\n"))
			return ("\0");
		else
			write(1, p->buf, p->len);
	}
	return (p->buf);
}

/*
** reed_line: чтение линии.
*/

void reed_line(int fd)
{
	t_parser p;

	p.step_history = -1;
	p.len_map = -1;
	p.flag_step_history_next = 0;
	p.flag_step_history_previou = 0;
	p.map = ft_calloc(500, sizeof(char *));
	p.str = ft_calloc(2, sizeof(char));
	while (ft_strcmp(p.buf, "\4"))
	{
		p.buf = ft_calloc(2, sizeof(char));
		tputs(save_cursor, 1, &ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		while (((p.len = read(0, p.buf, 100)) != -1) &&
		ft_strcmp(p.buf, "\n") && ft_strcmp(p.buf, "\4"))
		{
			p.backspace = 0;
			p.buf = get_line(&p);
			if (ft_strcmp(p.buf, "\e[C") && ft_strcmp(p.buf, "\e[B")
			&& ft_strcmp(p.buf, "\e[D") && ft_strcmp(p.buf, "\177")
			&& ft_strcmp(p.buf, "\e[A"))
			{
				if (!ft_strcmp(p.buf, "\0"))
					break ;
				p.str = ft_strjoin(p.str, p.buf);
				free(p.str);
			}
			if (p.backspace)
				p.str = delet_backspace(p.str, 1);
		}
		write(1, "\n", 1);
		p.step_history = p.len_map;
		set_line(ft_strjoin(p.str, "\n"), fd, &p);
		// if (ft_strlen(p.str) > 1)
			check_command(p.str, ft_strlen(p.str));
		ft_bzero(p.str, ft_strlen(p.str));
	}
}

/*
** parser: запуск парсера.
*/

void	parser(void)
{
	int				fd;
	struct	termios	term;

	term = init();
	fd = make_file();
	reed_line(fd);
	term.c_lflag |= ~(ECHO);
	term.c_lflag |= ~(ICANON);
}
