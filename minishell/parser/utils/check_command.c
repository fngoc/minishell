#include "../../parser/parser.h"

/*
** check_command: проверка строки на команды и кавычки.
*/

void	check_command(char *line, t_parser *p)
{
	char *name;
	int i;
	char *previous_char;

	p->map_comand = ft_calloc(500, sizeof(char *));
	i = -1;
	previous_char = NULL;
	name = NULL;
	while (*line != ';' && *line != '\0')
	{	
		if (ft_istab(*line))
		{
			previous_char = line;
			++line;
		}
		else
		{
			if (*line == '\"' || *line == '\'')
			{
				if (previous_char != NULL && *previous_char == ' ')
					name = NULL;
				++line;
				while ((*line != '\"' && *line != '\'') && *line != '\0')
				{
					name = ft_strjoin_char_free(name, *line++);
				}
				if (*line == '\0')
					error("Incorrect number of quotation marks");
				++line;
				if ((ft_istab(*line) || *line == '\0') && ft_strlen(line) >= 0)
				{
					if (ft_strlen(name) > 0)
					{
						p->map_comand[++i] = ft_strdup(name);
						free(name);
					}
					else
						p->map_comand[++i] = NULL;
				}
				previous_char = NULL;
			}
			else
			{
				if (previous_char != NULL && *previous_char == ' ')
					name = NULL;
				while (!ft_istab(*line) && *line != '\0')
				{
					if (*line == '\"' || *line == '\'')
						break ;
					name = ft_strjoin_char_free(name, *line++);
				}
				if (*line != '\"' && *line != '\'')
				{
					if (ft_strlen(name) > 0)
					{
						p->map_comand[++i] = ft_strdup(name);
						free(name);
					}
					else
						p->map_comand[++i] = NULL;
				}
				previous_char = NULL;
			}
		}
	}
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
