#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	print_env()
{
	t_list *tmp;

	tmp = params->env;
	while (params->env)
	{
		printf("%s\n", params->env->content);
		params->env = params->env->next;
	}
	params->env = tmp;
}
