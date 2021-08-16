#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const char	*tmp;

	tmp = arr;
	while (n-- != 0)
	{
		if (*tmp != c)
			tmp++;
		else
			return ((char *)tmp);
	}
	return (NULL);
}
