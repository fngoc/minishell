#include "../minishell.h"

char	*get_pwd(void)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	return (cwd);
}

void	print_pwd(void)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	ft_putstr_fd(cwd, 1);
	set_errno(0);
}
