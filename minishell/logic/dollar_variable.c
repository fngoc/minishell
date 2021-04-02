#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	dollar_variable(char *param)
{
	char *str;
	char *str2;

	t_list *tmp;

	tmp = params->env;

	str = get_var_param(tmp, param);
	if (!str)
		return;
	str2 = get_var_param(tmp, str);
	if (!str2)
		return;
	ft_putendl_fd(str2, 1);
}

