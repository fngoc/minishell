#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

int del_env_list(t_list **env, char *param)
{
	t_list **prev;
	t_list *temp;

	if (*env == NULL)
		return 0;
	prev = env;
	while ((*prev)->next)
	{
		if(ft_strncmp((*prev)->content, param, ft_strlen(param)) == 0
		   && ((int)((*prev)->content[ft_strlen(param)])) == '=')
		{
			temp = (*prev)->next;
			free((*prev)->content);
			free(*prev);
			*prev = temp;
			return 1;
		}
		prev = &((*prev)->next);
	}

	return (0);
}


void 	unset_var(char *var)
{
	t_list *tmp;

	tmp = params->env;
	params->env = get_env_list_pos(params->env, var);
	if (params->env == NULL)
		return ;
	free(params->env->content);
	params->env->content = "\0";
	params->env = tmp;
}

