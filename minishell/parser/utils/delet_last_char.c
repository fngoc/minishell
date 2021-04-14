#include "../../minishell.h"

/*
** delet_last_char: удаление из строки к-во char.
*/

char	*delet_last_char(char *str, int coll_backspace)
{
	int len;

	coll_backspace += 2;
	len = ft_strlen(str) + 1;
	while (coll_backspace-- != 0)
		str[len--] = '\0';
	return (str);
}
