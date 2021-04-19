#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- != 0)
	{
		if (((unsigned char *)src)[i] != (unsigned char)c)
		{
			*((unsigned char *)dst) = ((unsigned char *)src)[i++];
			++dst;
		}
		else
		{
			*((unsigned char *)dst) = ((unsigned char *)src)[i];
			++dst;
			return (dst);
		}
	}
	return (NULL);
}
