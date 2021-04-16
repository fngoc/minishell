#include "../../minishell.h"

/*
** single_quote: одна кавычка.
*/

char    *single_quote(char **line)
{
	char *str;

	str = NULL;
	++(*line);
	while (**line != '\'' && **line != '\0')
	{
		// if (**line == '\\')
		// 	++(*line);
		str = ft_strjoin_char_free(str, *(*line)++);
	}
	if (**line == '\0')
		error("Not a closed quote", 258);
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
