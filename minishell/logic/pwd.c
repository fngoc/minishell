#include "logic.h"

char	*get_pwd()
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	return cwd;
}

void 	print_pwd()
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	ft_putstr_fd(cwd, 1);
}
