#include "libft.h"

int	ft_isascii(int c)
{
	return (((c >= 0) && (c <= 0x7F)) ? 1 : 0);
}
