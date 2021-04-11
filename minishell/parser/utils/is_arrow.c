#include "../parser.h"

/*
** is_arrow: проверка.
*/

int	is_arrow(char const *buf)
{
	return (!(ft_strcmp(buf, "\e[C") && ft_strcmp(buf, "\e[B")
			&& ft_strcmp(buf, "\e[D") && ft_strcmp(buf, "\177")
			&& ft_strcmp(buf, "\e[A")));
}
