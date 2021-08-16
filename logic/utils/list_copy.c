#include "../../minishell.h"

t_list	*list_copy(void)
{
	t_list *tmp;
	t_list *new;

	tmp = g_params->env;
	new = NULL;
	while (g_params->env)
	{
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(g_params->env->content)));
		g_params->env = g_params->env->next;
	}
	g_params->env = tmp;
	return (new);
}
