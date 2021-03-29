#include "../../parser/parser.h"

/*
** check_command: проверка строки на команды.
*/

void	check_command(char *line, t_parser *p)
{
	char *name;
	int i;

	p->map_comand = ft_calloc(500, sizeof(char *));
	i = -1;
	while (*line != ';' && *line != '\0')
	{
		if (ft_istab(*line))
			++line;	
		else
		{
			name = NULL;
			while (!ft_istab(*line) && *line != '\0')
			{
				name = ft_strjoin_char_free(name, *line);
				++line;
			}
			p->map_comand[++i] = ft_strdup(name);
			free(name);
		}
	}
	// check_quotation_marks(p->map_comand);
	send_command_execute(p->map_comand);
	free_map(p->map_comand);
	if (ft_strlen(line) > 1)
		check_command(++line, p);

	/* Проверка */
	// int u;
	// u = 0;
	// while (u <= i)
	// 	printf("%s\n", p->map_comand[u++]);
	// free_map(p->map_comand);
}
