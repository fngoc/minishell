#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		len;
	int		i;
	char	endl;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	endl = '\n';
	len = ft_strlen(s);
	while (i < len)
		write(fd, &s[i++], 1);
	write(fd, &endl, 1);
}
