#include "parser.h"
#include "../libft/libft.h"

void	check_command(char *line, int size)
{
	char	*p;

	if ((p = ft_strnstr("echo", line, size)) != NULL)
		printf("Делаем команду echo\n");
	if ((p = ft_strnstr("cd", line, size)) != NULL)
		printf("Делаем команду cd\n");
	if ((p = ft_strnstr("pwd", line, size)) != NULL)
		printf("Делаем команду pwd\n");
	if ((p = ft_strnstr("export", line, size)) != NULL)
		printf("Делаем команду export\n");
	if ((p = ft_strnstr("unset", line, size)) != NULL)
		printf("Делаем команду unset\n");
	if ((p = ft_strnstr("env", line, size)) != NULL)
		printf("Делаем команду env\n");
	if ((p = ft_strnstr("exit", line, size)) != NULL)
		printf("Делаем команду exit\n");
}

/*
** get_history_previous: взять предыдущую историю.
*/

void get_history_previous(t_parser *p)
{
	ft_bzero(p->str, ft_strlen(p->str));
	p->str = ft_strdup(p->map[p->step_history]);
	--p->step_history;
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
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		get_history_previous(p);
		// write(1, "previous\n", 8);
	}
	else if (!ft_strcmp(p->buf, "\e[B")) //стрелочка вниз
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		write(1, "next\n", 4);
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
	else if (!ft_strcmp(p->buf, "\e[C") || !ft_strcmp(p->buf, "\e[D")) //замена клавишь влево и вправо
		return (p->buf);
	else // печать символа
		write(1, p->buf, p->len);
	return (p->buf);
}

/*
** reed_line: чтение линии.
*/

void reed_line(int fd)
{
	t_parser p;

	p.coll_previous = 0;
	p.step_history = 0;
	p.len_map = 0;
	p.map = ft_calloc(500, sizeof(char *));
	p.buf = ft_calloc(2, sizeof(char));
	p.str = ft_calloc(2, sizeof(char));
	while (ft_strcmp(p.buf, "\4"))
	{
		tputs(save_cursor, 1, &ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		while (((p.len = read(0, p.buf, 100)) != -1) &&
		ft_strcmp(p.buf, "\n") && ft_strcmp(p.buf, "\4"))
		{
			p.backspace = 0;
			p.buf = get_line(&p);
			if (ft_strcmp(p.buf, "\e[C") && ft_strcmp(p.buf, "\e[D")
			&& ft_strcmp(p.buf, "\177") && ft_strcmp(p.buf, "\e[A"))
			{
				p.str = ft_strjoin(p.str, p.buf);
				free(p.str);
			}
			if (p.backspace)
				p.str = delet_backspace(p.str, 1);
		}
		write(1, "\n", 1);
		set_line(ft_strjoin(p.str, "\n"), fd, &p);
		ft_bzero(p.str, ft_strlen(p.str));
	}
	/* Проверка */
	int i;

	i = 0;
	while (i < p.len_map)
	{
		printf("%s\n", p.map[i++]);
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
