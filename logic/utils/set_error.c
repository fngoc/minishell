#include "../../minishell.h"

void	set_errno(int err)
{
	char *tmp;
	char *res;

	tmp = ft_itoa(err);
	res = ft_strjoin("err=", tmp);
	export_var(res);
	free(tmp);
	free(res);
}
