#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	print_env()
{
	t_list *tmp;

	tmp = params->env;
	while (params->env)
	{
		ft_putstr_fd(params->env->content, 1);
		params->env = params->env->next;
	}
	params->env = tmp;
}
