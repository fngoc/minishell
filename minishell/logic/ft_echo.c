#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

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
			if ((tmp = get_var_param(params->env, ++tmp)))
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
					if ((tmp = get_var_param(params->env, ++tmp)))
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
			if ((tmp = get_var_param(params->env, ++tmp)))
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
			str = ft_strjoin_fix(str, single_quote(line));
		else if (**line == '\"')
			str = ft_strjoin_fix(str, double_quote(line));
		else
			str = ft_strjoin_fix(str, without_quotation_marks(line));
	}
	return (str);
}

static	char	**pars_line_echo(char *line)
{
	char *str_arg;
	char **map_arg;
	int i;
	
	i = -1;
	map_arg = ft_calloc(500, sizeof(char **));
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
				map_arg[++i] = ft_strdup(str_arg);
			// free(str_arg);
		}
	}
	return (map_arg);
}

void 	ft_echo(char *line, int n_flag)
{
	char **map_arg;
	
	map_arg = ft_calloc(500, sizeof(char **));
	map_arg = pars_line_echo(line);
	while (*map_arg != NULL)
	{
		ft_putstr_fd(*map_arg++, 1);
		if (*map_arg != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (n_flag == 0)
		ft_putchar_fd('\n', 1);
}
