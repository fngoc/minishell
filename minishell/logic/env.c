#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	print_env()
{
	t_list *tmp;

	tmp = params->env;
	while (params->env)
	{
		if (ft_strncmp("err", params->env->content, 3) == 0)
		{
			params->env = params->env->next;
			continue;
		}
		ft_putstr_fd(params->env->content, 1);
		params->env = params->env->next;
		write(1, "\n", 1);
	}
	params->env = tmp;
	set_errno(0);
}
