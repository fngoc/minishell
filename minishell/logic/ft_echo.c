#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

/*
** delet_first: удалить первый символ строки.
*/

static	char	*delet_first(char *str)
{
	char *new_char;
	char *tmp;

	tmp = str;
	new_char = ++str;
	free(tmp);
	return (new_char);
}

/*
** ft_strjoin_fix: чистит первый аргумент.
*/

static char	*ft_strjoin_fix(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		++i;
		++j;
	}
	p[i] = '\0';
	return (p);
}

/*
** ft_strjoin_free_free: чистить все аргументы.
*/

static char	*ft_strjoin_free_free(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		++i;
		++j;
	}
	free(s2);
	p[i] = '\0';
	return (p);
}

/*
** single_quote: одна кавычка.
*/

static char *single_quote(char **line)
{
	char *str;

	str = NULL;
	++(*line);
	while (**line != '\'' && **line != '\0')
		str = ft_strjoin_char_free(str, *(*line)++);
	if (**line == '\0')
		error("Not a closed quote");
	++(*line);
	return (str);
}

/*
** without_quotation_marks: без кавычек.
*/

static char *without_quotation_marks(char **line)
{
	char *str;
	char *tmp;

	str = NULL;
	while (**line != ' ' && **line != '\0')
	{
		if (**line == '$')
		{
			tmp = NULL;
			while (**line != ' ' && **line != '\"' && **line != '\'' && **line != '\0')
				tmp = ft_strjoin_char_free(tmp, *(*line)++);
			if ((tmp = get_var_param(params->env, delet_first(tmp))))
			{
				if (str != NULL)
					str = ft_strjoin_fix(str, tmp);
				else
					str = ft_strdup(tmp);
			}
		}
		if (**line == '\"')
		{
			++(*line);
			while (**line != '\"' && **line != '\0')
			{
				if (**line != '$')
					str = ft_strjoin_char_free(str, *(*line)++);
				if (**line == '$')
				{
					tmp = NULL;
					while (**line != ' ' && **line != '\"' && **line != '\'')
						tmp = ft_strjoin_char_free(tmp, *(*line)++);
					if ((tmp = get_var_param(params->env, delet_first(tmp))))
					{
						if (str != NULL)
							str = ft_strjoin_fix(str, tmp);
						else
							str = tmp;
					}
				}
			}
			if (**line == '\"')
				++(*line);
		}
		if (**line == '\'')
		{
			++(*line);
			while (**line != '\'' && **line != '\0')
				str = ft_strjoin_char_free(str, *(*line)++);
			if (**line == '\'')
				++(*line);
		}
		if (ft_strlen(*line) > 0)
			str = ft_strjoin_char_free(str, *(*line)++);
	}
	return (str);
}

/*
** double_quote: двайная кавычка.
*/

static char *double_quote(char **line)
{
	char *str;
	char *tmp;

	str = NULL;
	++(*line);
	while (**line != '\"' && **line != '\0')
	{
		if (**line != '$')
			str = ft_strjoin_char_free(str, *(*line)++);
		if (**line == '$')
		{
			tmp = NULL;
			while (**line != ' ' && **line != '\"' && **line != '\'')
				tmp = ft_strjoin_char_free(tmp, *(*line)++);
			if ((tmp = get_var_param(params->env, delet_first(tmp))))
			{
				if (str != NULL)
					str = ft_strjoin_fix(str, tmp);
				else
					str = ft_strdup(tmp);
			}
		}
	}
	++(*line);
	if (**line != ' ' && **line != '\0')
	{
		if (**line == '\'')
			str = ft_strjoin_free_free(str, single_quote(line));
		else if (**line == '\"')
			str = ft_strjoin_free_free(str, double_quote(line));
		else
			str = ft_strjoin_free_free(str, without_quotation_marks(line));
	}
	return (str);
}

/*
** pars_line_echo: парсинг строки для echo.
*/

static	char	**pars_line_echo(char *line, int memory)
{
	char *str_arg;
	char **map_arg;
	int i;

	i = -1;
	map_arg = ft_calloc(memory + 1, sizeof(char **));
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
