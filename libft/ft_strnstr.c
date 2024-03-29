#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		*segfault;
	size_t	needle_len;

	i = 0;
	segfault = 0;
	if (haystack == NULL || needle == NULL)
		*segfault = 1;
	if ((needle_len = ft_strlen(needle)) == 0)
		return ((char *)haystack);
	while (i++ <= (int)(len - needle_len))
	{
		if ((haystack[0] == needle[0]) &&
			(ft_strncmp(haystack, needle, needle_len)) == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
