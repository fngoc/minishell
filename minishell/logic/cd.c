#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void cd(char *dir)
{
	char *old_content;
	t_list *ptr;

	ptr = params->env;
	old_content = ft_strdup(env_var_full_param(params->env, "OLDPWD"));
	if (chdir(dir) == -1)
	{
		printf("no such file or directory %s\n", dir);
		return;
	}
	else
	{
//		params->env = env_list_pos(ptr, "PWD");
//		free(params->env->content);
//		params->env->content = change_value_by_key("PWD", pwd());
//		params->env = env_list_pos(ptr, "OLDPWD");
//		free(params->env->content);
//		params->env->content = old_content;
//		free(old_content);
		ptr = env_list_pos(params->env, "PWD");
		free(ptr->content);
		ptr->content = change_value_by_key("PWD", pwd());

		ptr = env_list_pos(params->env, "OLDPWD");
		free(ptr->content);
		ptr->content = old_content;
		free(old_content);
	}
}