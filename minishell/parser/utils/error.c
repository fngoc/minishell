#include "../../logic/logic.h"
#include "../../parser/parser.h"
#include "../../libft/libft.h"

/*
** error: печатает текст ошибки и выходит из программы.
*/

void	error(char *str, int err)
{
	char *tmp;
	char *res;

	ft_putendl_fd(str, 2);
	tmp = ft_itoa(err);
	res = ft_strjoin( "err=",tmp);
	export_var(res);
	free(tmp);
	free(res);
	exit(err);
}
