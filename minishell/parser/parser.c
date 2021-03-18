#include "parser.h"
#include "../libft/libft.h"

void	check_for_command(char *line, int size)
{
	char *p;

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
** parser: запуск парсера.
*/

void	parser(void)
{
<<<<<<< HEAD
//	struct termios term;
=======
	int		len;
	char	str[2000];
	struct	termios term;
>>>>>>> 0aec69c6d5911bc6e037f703688d191ece71e3a8

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, "xterm-256color");
	while (strcmp(str, "\4"))
	{
		tputs(save_cursor, 1, &ft_putchar);
		do
		{
			len = read(0, str, 100);
			str[len] = 0;
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
			else if (!strcmp(str, "\177")) //|| !strcmp(str, key_backspace))
			{
				tputs(cursor_left, 1, ft_putchar);
				tputs(tgetstr("dc", 0), 1, ft_putchar);
			}
			else
				write(1, str, len);
		} while (strcmp(str, "\n") && strcmp(str, "\4"));
	}
	write(1, "\n", 1);
	term.c_lflag |= ~(ECHO);
	term.c_lflag |= ~(ICANON);
}
