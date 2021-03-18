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
	struct termios term;

	
	
	// char *buf;
	// char *line_command;

	// buf = malloc(sizeof(char ) + 1);
	// buf[1] = '\0';
	// if (!(line_command = (char *)malloc(sizeof(char) * 1)))
	// 	error("Alloc error\n");
	// while ((read(0, buf, 1)) != 0 && buf[0] != '\n')
	// {
	// 	line_command = ft_strjoin(line_command, buf);
	// 	check_for_command(line_command, ft_strlen(line_command));
	// }
	// printf("Вся линия: %s\n", line_command);
}
