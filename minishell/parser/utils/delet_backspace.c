#include "../../parser/parser.h"
#include "../../libft/libft.h"

/*
** delet_backspace: удаление из строки к-во backspace.
*/

char    *delet_backspace(char *str, int coll_backspace)
{
	int len;

	coll_backspace += 2;
	len = ft_strlen(str) + 1;
	while (coll_backspace-- != 0)
	{
		str[len--] = '\0';
	}
	return (str);
}
