#include "../../../logic/logic.h"
#include "../../parser.h"
#include "../../../libft/libft.h"

/*
** pars_line_echo: парсинг строки для echo.
*/

static	char	**pars_line_echo(char *line, int memory)
{
	char *str_arg;
	char **map_arg;
	int i;

	i = -1;
	if (!(map_arg = ft_calloc(memory * 2, sizeof(char **))))
		error("Allocated error", 11);
	while (*line != '\0')
	{
		if (*line == ' ')
			++line;
		else
		{
			str_arg = NULL;
			if (*line == '\'')
				str_arg = single_quote(&line);
			else if (*line == '\"')
				str_arg = double_quote(&line);
			else
				str_arg = without_quotation_marks(&line);
			if (str_arg != NULL)
			{
				map_arg[++i] = ft_strdup(str_arg);
				free(str_arg);
			}
		}
	}
	return (map_arg);
}

/*
** ft_echo: команда echo.
*/

void 	ft_echo(char *line, int n_flag, int memory)
{
	char **map_arg;
	char **tmp;

	map_arg = pars_line_echo(line, memory);
	tmp = map_arg;
	while (*map_arg != NULL)
	{
		ft_putstr_fd(*map_arg, 1);
		if ((*map_arg)[ft_strlen(*map_arg) - 1] == ' ')
		{
			free(*map_arg);
			++map_arg;
		}
		else
		{
			free(*map_arg);
			++map_arg;
			if (*map_arg != NULL)
				ft_putchar_fd(' ', 1);
		}
	}
	free(tmp);
	if (n_flag == 0)
		ft_putchar_fd('\n', 1);
}
