#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//str - аргумент, который надо напечатать, n flag - перевод строки
void 	echo(char *str, int n_flag)
{
	if (n_flag == 1)
	{
		ft_putstr_fd(str, 1);
		ft_putchar('\n');
	}
	else
		ft_putstr_fd(str, 1);
}

