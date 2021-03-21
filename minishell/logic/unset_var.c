#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	unset_var(char *var)
{
	t_list *tmp;

	tmp = params->env;
	params->env = get_env_list_pos(params->env, var);
	free(params->env->content);
	params->env->content = "\0";
	params->env = tmp;
}

