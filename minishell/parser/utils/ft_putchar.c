# include "../parser.h"

/*
** ft_putchar: печать символа для функции tputs.
*/

int ft_putchar(int c)
{
	return (write(1, &c, 1));
}
