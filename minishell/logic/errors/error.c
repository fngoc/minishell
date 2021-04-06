#include "../logic.h"
#include "../../parser/parser.h"
#include "../../libft/libft.h"

void 	errno_exit()
{
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

