#include "../../minishell.h"

void	error(char *str, int err)
{
	char *tmp;
	char *res;

	ft_putendl_fd(str, 2);
	tmp = ft_itoa(err);
	res = ft_strjoin("err=", tmp);
	export_var(res);
	free(tmp);
	free(res);
	exit(err);
}
