#include "../../parser/parser.h"

/*
** quotation_mark_found: найдена кавычка.
*/

static	void quotation_mark_found(t_parser *p, int *i, char **p_c, char **name, char **line)
{
	char what;
	if (*p_c != NULL && **p_c == ' ')
		*name = NULL;
	what = **line;
	++(*line);
	if (what == '\'')
	{
		while (what == '\'' && **line != '\'' && **line != '\0')//(**line != '\"' && **line != '\'') && **line != '\0')
		{
			*name = ft_strjoin_char_free(*name, **line);
			++(*line);
		}
	}
	else
	{
		while ((**line != '\"' && **line != '\'') && **line != '\0')
		{
			*name = ft_strjoin_char_free(*name, **line);
			++(*line);
		}
	}
	if (**line == '\0')
		error("Incorrect number of quotation marks");
	++(*line);
	if ((ft_istab(**line) || **line == '\0') && ft_strlen(*line) >= 0)
	{
		if (ft_strlen(*name) > 0)
		{
			p->map_comand[++*i] = ft_strdup(*name);
			free(*name);
		}
		else
			p->map_comand[++*i] = NULL;
	}
	*p_c = NULL;
}

/*
** quotation_mark_not_found: кавычка не найдена.
*/

static	void quotation_mark_not_found(t_parser *p, int *i, char **p_c, char **name, char **line)
{
	if (*p_c != NULL && **p_c == ' ')
		*name = NULL;
	while (!ft_istab(**line) && **line != '\0')
	{
		if (**line == '$')
			p->flag_echo = 1;
		if (**line == '\"' || **line == '\'')
			break ;
		*name = ft_strjoin_char_free(*name, **line);
		++(*line);
	}
	if (**line != '\"' && **line != '\'')
	{
		if (ft_strlen(*name) > 0)
		{
			p->map_comand[++*i] = ft_strdup(*name);
			free(*name);
		}
		else
			p->map_comand[++*i] = NULL;
	}
	*p_c = NULL;
}

/*
** check_command: проверка строки на команды и кавычки.
*/

void	check_command(char *line, t_parser *p)
{
	char *name;
	char *previous_char;
	int i;

	p->map_comand = ft_calloc(500, sizeof(char *));
	previous_char = NULL;
	name = NULL;
	i = -1;
	if (*line == ';')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		error("You can not write at the beginning of the command ;");
	}
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
				if (*line == '\"')
				{
					p->flag_echo = 1;
					p->flag_quotation_mark = 1;
				}
				if (*line == '\'')
					p->flag_echo = 0;
				quotation_mark_found(p, &i, &previous_char, &name, &line);
			}
			else
				quotation_mark_not_found(p, &i, &previous_char, &name, &line);
		}
	}
	send_command_execute(p->map_comand, p);
	free_map(p->map_comand);
	if (ft_strlen(line) > 1)
		check_command(++line, p);
	p->flag_echo = 0;
	p->flag_quotation_mark = 0;
}
