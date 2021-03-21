#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static	int cd_error(int fd, char *dir)
{
	if (fd == -1)
	{
		fd = open(dir, O_RDONLY);
		if (fd == -1)
			printf("cd : %s: No such file or directory\n", dir);
		else
			printf("cd : %s: Not a directory\n", dir);
		return (0);
	}
	return (1);
}

void	cd(char *dir)
{
	char *old_content;
	t_list *start;
	int fd;

	start = params->env;
	old_content = ft_strdup(get_var_param(params->env, "PWD"));
	if (*dir == '\0')
		dir = get_var_param(params->env, "HOME");
	fd = open(dir, O_DIRECTORY);

	if (!cd_error(fd, dir))
		return ;
	else
	{
		chdir(dir);
		params->env = get_env_list_pos(start, "PWD");
		free(params->env->content);
		params->env->content = change_value_by_key("PWD", get_pwd());
		params->env = get_env_list_pos(start, "OLDPWD");
		free(params->env->content);
		params->env->content = change_value_by_key("OLDPWD", old_content);
		params->env = start;
		free(old_content);
	}
}