#include "../../minishell.h"

/*
** without_quotation_marks: без кавычек.
*/

char    *without_quotation_marks(char **line)
{
	char	*str;
	char	*tmp;
	char	*buf;
	int		flag;

	flag = 0;
	str = NULL;
	buf = NULL;
	while (**line != ' ' && **line != '\0')
	{
		if (**line == '$')
		{
			tmp = NULL;
			while (**line != ' ' && **line != '\"' && **line != '\'' && **line != '\0')
			{
				if (**line == '\\')
				{
					++(*line);
					flag = 1;
					buf = ft_strjoin_char_free(buf, **line);
					continue ;
				}
				tmp = ft_strjoin_char_free(tmp, *(*line)++);
			}
			if ((tmp = get_var_param(params->env, delet_first(tmp))))
			{
				if (str != NULL)
					str = ft_strjoin_fix(str, tmp);
				else
					str = ft_strdup(tmp);
			}
			if (flag)
				str = ft_strjoin_fix(str, buf);
		}
		if (**line == '\"')
		{
			++(*line);
			while (**line != '\"' && **line != '\0')
			{
				if (**line != '$')
				{
					if (**line == '\\')
						++(*line);
					str = ft_strjoin_char_free(str, *(*line)++);
				}
				if (**line == '$')
				{
					tmp = NULL;
					while (**line != ' ' && **line != '\"' && **line != '\'')
					{
						if (**line == '\\')
						{
							++(*line);
							continue ;
						}
						tmp = ft_strjoin_char_free(tmp, *(*line)++);
					}
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
			if (**line == '\'')
			{
				++(*line);
				continue ;
			}
			else
			{
				while (**line != '\'' && **line != '\0')
				{
					if (**line == '\\')
						++(*line);
					str = ft_strjoin_char_free(str, *(*line)++);
				}
			}
			if (**line == '\'')
				++(*line);
			if (**line == '\"')
				continue ;
		}
		if (ft_strlen(*line) > 0)
		{
			if (**line == '\\')
				++(*line);
			str = ft_strjoin_char_free(str, *(*line)++);
		}
	}
	return (str);
}
