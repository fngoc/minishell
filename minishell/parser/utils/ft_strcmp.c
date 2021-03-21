#include "../parser.h"

/*
** ft_strcmp: побайтно сравнивает коды
** символов двух строк, на которые указывают
** аргументы функции.
*/

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if ((unsigned char)str1[i] == (unsigned char)str2[i])
			++i;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}