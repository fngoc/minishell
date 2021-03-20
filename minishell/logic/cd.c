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
		ptr = env_list_pos(params->env, "PWD");
		free(ptr->content);
		ptr->content = change_value_by_key("PWD", get_pwd());
		ptr = env_list_pos(params->env, "OLDPWD");
		free(ptr->content);
		ptr->content = old_content;
		free(old_content);
	}
}