#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = b;
	while (len-- != 0)
		*tmp++ = c;
	return (b);
}
