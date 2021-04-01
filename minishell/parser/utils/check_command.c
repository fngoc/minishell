#include "../../parser/parser.h"

// static	char	*single_quote(char *line, char *name)
// {
// 	line++;
// 	while (*line != '\'' && *line != '\0')
// 	{
// 		name = ft_strjoin_char_free(name, *line);
// 		++line;
// 	}
// 	return(name);
// }

// static	char	*double_quote(char *line, char *name)
// {
// 	line++;
// 	while (*line != '\"' && *line != '\0')
// 	{
// 		name = ft_strjoin_char_free(name, *line);
// 		++line;
// 	}
// 	return(name);
// }

/*
** command_entry: запись команды и обработка кавычек.
*/

// static	char	*command_entry(char *line, t_parser *p, int i)
// {
// 	char *name;

// 	name = NULL;
// 	while (!ft_istab(*line) && *line != '\0')
// 	{
// 		if (*line == '\'')
// 		{
// 			line++;
// 			while (*line != '\'' && *line != '\0')
// 			{
// 				name = ft_strjoin_char_free(name, *line);
// 				++line;
// 			}
// 		}
// 		else if (*line == '\"')
// 		{
// 			line++;
// 			while (*line != '\"' && *line != '\0')
// 			{
// 				name = ft_strjoin_char_free(name, *line);
// 				++line;
// 			}
// 		}
// 		else
// 			name = ft_strjoin_char_free(name, *line++);
// 	}
// 	if (name == NULL && i == 0)
// 		error("Error: Empty command");
// 	p->map_comand[i] = ft_strdup(name);
// 	free(name);
// 	return (line);
// }

/*
** handling_quotation_marks: обработка кавычек
** и запись команд в двумерный массив.
*/

char *handling_quotation_marks(char *name, t_parser *p)
{
	int i;
	char *new_name;

	i = -1;
	new_name = NULL;
	while (*name != '\0')
	{
		if (*name != '\'' && *name != '\"' && *name != ' ')
			new_name = ft_strjoin_char_free(new_name, *name);
		++name;
	}
	p->map_comand[++i] = ft_strdup(new_name);
	free(new_name);
	return (new_name);
}

/*
** check_command: проверка строки на команды.
*/

void	check_command(char *line, t_parser *p)
{
	char *name;

	p->map_comand = ft_calloc(500, sizeof(char *));
	name = NULL;
	while (*line != ';' && *line != '\0')
	{
		if (ft_istab(*line))
			++line;
		else if (*line == '\'')
		{
			name = ft_strjoin_char_free(name, *line++);
			while (*line != '\'' && *line != '\0')
				name = ft_strjoin_char_free(name, *line++);
			name = ft_strjoin_char_free(name, *line++);
		}
		else if (*line == '\"')
		{
			name = ft_strjoin_char_free(name, *line++);
			while (*line != '\"' && *line != '\0')
				name = ft_strjoin_char_free(name, *line++);
			name = ft_strjoin_char_free(name, *line++);
		}
		else
			name = ft_strjoin_char_free(name, *line++);
	}
	name = handling_quotation_marks(name, p);
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
