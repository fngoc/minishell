#include "../minishell.h"

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
		while (what == '\'' && **line != '\'' && **line != '\0')
		{
			if (**line == '\\')
			{
				++(*line);
				*name = ft_strjoin_char_free(*name, **line);
				++(*line);
				continue ;
			}
			*name = ft_strjoin_char_free(*name, **line);
			++(*line);
		}
	}
	else
	{
		while ((**line != '\"' && **line != '\'') && **line != '\0')
		{
			if (**line == '\\')
			{
				++(*line);
				*name = ft_strjoin_char_free(*name, **line);
				++(*line);
				continue ;
			}
			*name = ft_strjoin_char_free(*name, **line);
			++(*line);
		}
	}
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
	while (!ft_istab(**line) && **line != ';' && **line != '|' && **line != '>' && **line != '<' && **line != '\0')
	{
		if (**line == '\"' || **line == '\'')
			break ;
		if (**line == '\\')
		{
			++(*line);
			*name = ft_strjoin_char_free(*name, **line);
			++(*line);
			continue ;
		}
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
** check_echo_flag_n: проверка на -n.
*/

int	check_echo_flag_n(char **line)
{
	while (**line != '\0')
	{
		if (ft_istab(**line))
			++(*line);
		if (**line == ';')
			return (2);
		if (**line == '-')
		{
			++(*line);
			if (**line == 'n')
			{
				++(*line);
				return (1);
			}
		}
		else
			return (0);
	}
	return (0);
}

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
	p->map_comand[++*i] = ft_strdup(name);
	free(name);
}

/*
** parser_commands: проверка строки на команды и кавычки.
*/

void	parser_commands(char *line, t_parser *p, t_file *file)
{
	char *name;
	char *previous_char;
	int i;

	name = NULL;
	previous_char = NULL;
	if (!(p->map_comand = ft_calloc(500, sizeof(char *))))
		error("Allocated error", 11);
	i = -1;
	if (*line == ';')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		error("You can not write at the beginning of the command ;", 258);
	}
	if (*line == '|')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		error("You can not write at the beginning of the command |", 258);
	}
	while (*line != ';' && *line != '|' && *line != '<' && *line != '>' && *line != '\0')
	{
		if (ft_istab(*line))
		{
			previous_char = line;
			++line;
		}
		else
		{
			if (i >= 499)
				error("Exceeded the limit on the number of commands per line", 11);
			if (*line == '\"' || *line == '\'')
				quotation_mark_found(p, &i, &previous_char, &name, &line);
			else
				quotation_mark_not_found(p, &i, &previous_char, &name, &line);
			if (p->map_comand[0] != NULL && !ft_strcmp(p->map_comand[0], "echo"))
			{
				p->flag_echo_n = check_echo_flag_n(&line);
				if (p->flag_echo_n == 0 || p->flag_echo_n == 1)
					parser_echo(p, &line, &i);
				break ;
			}
		}
	}
	if (*line == '|')
	{
		get_pipe_id(file);
		pipe_process(p->map_comand, p, file);
	}
	else if ((*line == '>' || *line == '<') && p->flag_redir == 0)
	{
		line = what_is_redir(line, p, p->map_comand);
		set_redir_map(p);
	}
	else if (p->flag_redir != 0)
	{
		parser_redir(p->map_comand, p, file, *line);
		dup2(1, STDIN_FILENO);
		dup2(0, STDOUT_FILENO);
	}
	else
	{
		send_command_execute(p->map_comand, p);
		dup2(1, STDIN_FILENO);
		dup2(0, STDOUT_FILENO);
	}
	free_map(p->map_comand);
	if (ft_strlen(line) > 1)
		parser_commands(++line, p, file);
	p->flag_echo_n = 0;
	p->flag_quotation_mark = 0;
}
