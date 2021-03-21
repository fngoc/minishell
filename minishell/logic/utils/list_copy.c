#include "../logic.h"
#include "../../parser/parser.h"
#include "../../libft/libft.h"

t_list *list_copy()
{
	t_list *tmp;
	t_list *new;

	tmp = params->env;
	new = NULL;
	while (params->env) {
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(params->env->content)));
		params->env = params->env->next;
	}
	params->env = tmp;
	return (new);
}

