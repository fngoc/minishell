#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	print_env(t_list *env)
{
	while (env)
	{
		printf("%s", (char *)env->content);
		env = env->next;
	}
}
