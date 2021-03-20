#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static void		print_export(t_list *tmp_src)
{
	params->env = tmp_src;
	while (params->env)
	{
		if (params->env->next != NULL)
			printf("declare -x %s\n", (char*)params->env->content);
		else
			printf("declare -x %s", (char*)params->env->content);
		params->env = params->env->next;
	}
	params->env = tmp_src;
}

void			export()
{
	t_list *tmp_src;
	char *tmp_str;
	int len;
	int i;
	int j;

	tmp_src = params->env;
	len = ft_lstsize(params->env) - 1;
	i = -1;
	while (++i < len)
	{
		j = -1;
		params->env = tmp_src;
		while (++j < len)
		{
			if (ft_strncmp(params->env->content, params->env->next->content, ft_strlen(params->env->content)) > 0)
			{
				tmp_str = params->env->next->content;
				params->env->next->content = params->env->content;
				params->env->content = tmp_str;
			}
			params->env = params->env->next;
		}
	}
	print_export(tmp_src);
}
