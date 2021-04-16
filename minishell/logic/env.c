#include "../minishell.h"

int		check_null_value(char *content)
{
	int i = -1;

	while (content[++i])
	{
		if (content[i] == '=')
		{
			return (0);
		}
	}
	return (1);
}

void 	print_env()
{
	t_list *tmp;

	tmp = params->env;
	int check;

	check = 0;
	while (params->env)
	{
		if (check == 0) {
			if (ft_strncmp("err", params->env->content, 3) == 0)
			{
				params->env = params->env->next;
				check = 1;
				continue;
			}
		}
		if (check_null_value(params->env->content) == 1)
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
