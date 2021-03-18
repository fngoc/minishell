#include "../logic/logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

/*
** error: печатает текст ошибки и выходит из программы.
*/

void	error(char *str)
{
    ft_putendl_fd(str, 1);
    exit(1);
}