#include "../../minishell.h"

static	void	branching_quote(char **str, char **line)
{
	++(*line);
	if (**line != ' ' && **line != '\0')
	{
		if (**line == '\'')
			*str = ft_strjoin_free_free(*str, single_quote(line));
		else if (**line == '\"')
			*str = ft_strjoin_free_free(*str, double_quote(line));
		else
			*str = ft_strjoin_free_free(*str, without_quotation_marks(line));
	}
}

char			*double_quote(char **line)
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
			if ((tmp = get_var_param(g_params->env, delet_first(tmp))))
			{
				if (str != NULL)
					str = ft_strjoin_fix(str, tmp);
				else
					str = ft_strdup(tmp);
			}
		}
	}
	branching_quote(&str, line);
	return (str);
}
