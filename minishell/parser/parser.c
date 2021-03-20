#include "parser.h"
#include "../libft/libft.h"

void	check_for_command(char *line, int size)
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
** set_line: установка линиии в историю.
*/

void set_line(char *str, int fd)
{
	if (write(fd, str, 1) != (int)ft_strlen(str))
		error("Failed to write a string to a file");
}

/*
** get_line: считываем линию.
*/

void	get_line(int *len, char *str, int fd)
{
	*len = read(0, str, 100);
	str[*len] = 0;
	if (!strcmp(str, "\e[A"))
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "previous", 8);
	}
	else if (!strcmp(str, "\e[B"))
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "next", 4);
	}
	else if (!strcmp(str, "\177"))
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		set_line(str, fd);
	}
	else
	{
		write(1, str, *len);
		set_line(str, fd);
	}
}

/*
** make_file: создаем фаил с иторией.
*/

int make_file(void)
{
	int fd;

	if (!(fd = open("minishell_history", O_CREAT, S_IWRITE | S_IREAD)))
		error("Error when creating a file with the history");
	if (!(fd = open("minishell_history", O_RDWR)))
		error("An error occurred while opening the history file");
	return (fd);
}

/*
** parser: запуск парсера.
*/

void	parser(void)
{
	int		fd;
	int		len;
	char	str[2000];
	struct	termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, "xterm-256color");
	fd = make_file();
	while (strcmp(str, "\4"))
	{
		tputs(save_cursor, 1, &ft_putchar);
		get_line(&len, str, fd);
		while (strcmp(str, "\n") && strcmp(str, "\4"))
		{
			get_line(&len, str, fd);
		}
	}
	write(1, "\n", 1);
	term.c_lflag |= ~(ECHO);
	term.c_lflag |= ~(ICANON);
}
