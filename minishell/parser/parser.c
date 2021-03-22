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
** get_line: считываем линию.
*/

char	*get_line(char *buf, char *str, int len, int *coll_backspace)
{
	buf[len] = 0;
	if (!ft_strcmp(buf, "\e[A")) //стрелочка вверх
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		write(1, "previous\n", 8);
	}
	else if (!ft_strcmp(buf, "\e[B")) //стрелочка вниз
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		write(1, "next\n", 4);
	}
	else if (!ft_strcmp(buf, "\177")) //клавиша backspase
	{
		if (ft_strlen(str) != 0)
		{
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", 0), 1, ft_putchar);
			write(1, buf, len);
			++*coll_backspace;
		}
	}
	else if (!ft_strcmp(buf, "\e[C") || !ft_strcmp(buf, "\e[D")) //замена клавишь влево и вправо
		return (buf);
	else // печать символа
		write(1, buf, len);
	return (buf);
}

/*
** delet_backspace: удаление из строки к-во backspace.
*/

char *delet_backspace(char *str, int coll_backspace)
{
	int len;

	coll_backspace += 2;
	len = ft_strlen(str) + 1;
	while (coll_backspace-- != 0)
	{
		str[len--] = '\0';
	}
	return (str);
}

/*
** reed_line: чтение линии.
*/

void reed_line(int fd)
{
	char	*buf;
	char	*str;
	int		len;
	int		coll_backspace;

	buf = ft_calloc(2, sizeof(char));
	str = ft_calloc(2, sizeof(char));
	while (ft_strcmp(buf, "\4"))
	{
		coll_backspace = 0;
		tputs(save_cursor, 1, &ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		while (((len = read(0, buf, 100)) != -1) &&
		ft_strcmp(buf, "\n") && ft_strcmp(buf, "\4"))
		{
			buf = get_line(buf, str, len, &coll_backspace);
			if (ft_strcmp(buf, "\e[C") && ft_strcmp(buf, "\e[D") && ft_strcmp(buf, "\177"))
			{
				str = ft_strjoin(str, buf);
				free(str);
			}
			if (coll_backspace)
				str = delet_backspace(str, 1);
		}
		write(1, "\n", 1);
		printf("coll_backspace: %d\n", coll_backspace);
		printf("str: %s\n", str);
		set_line(ft_strjoin(str, "\n"), fd);
		ft_bzero(str, ft_strlen(str));
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
