#include "../../minishell.h"

/*
** parser_echo: парсим echo.
*/

void parser_echo(t_parser *p, char **line, int *i)
{
	char *name;
	int flag_mark;

	flag_mark = 0;
	if (!**line)
	{
		p->map_comand[++*i] = NULL;
		return ;
	}
	name = NULL;
	if (**line == '\'' || **line == '\"')
	{
		flag_mark = 1;
		name = ft_strjoin_char_free(name, **line);
		++(*line);
	}
	while ((**line != ';' && **line != '|' && **line != '>' && **line != '<' && **line != '\0') || flag_mark == 1)
	{
		if (**line == '-' && *(*line + 1) == 'n' && *(*line + 2) == ' ' && p->flag_echo_n == 1)
		{
			++(*line);
			++(*line);
		}
		if (**line == '\\')
		{
			name = ft_strjoin_char_free(name, *(*line)++);
			name = ft_strjoin_char_free(name, *(*line)++);
			continue ;
		}
		if ((**line == '\'' || **line == '\"') && flag_mark == 1)
			flag_mark = 0;
		else if ((**line == '\'' || **line == '\"'))
			flag_mark = 1;
		name = ft_strjoin_char_free(name, **line);
		++(*line);
		if (**line == '\0')
			break ;
	}
	if (ft_strlen(name) == 0)
		error("Syntax error near unexpected token", 258);
	p->map_comand[++*i] = ft_strdup(name);
	free(name);
}
