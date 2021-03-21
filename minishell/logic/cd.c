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
	t_list *ptr;
	int fd;

	old_content = ft_strdup(env_var_full_param(params->env, "OLDPWD"));
	if (*dir == '\0')
		dir = env_var_param(params->env, "HOME");
	fd = open(dir, O_DIRECTORY);

	if (!cd_error(fd, dir))
		return ;
	else
	{
		chdir(dir);
		ptr = env_list_pos(params->env, "PWD");
		free(ptr->content);
		ptr->content = change_value_by_key("PWD", get_pwd());
		ptr = env_list_pos(params->env, "OLDPWD");
		free(ptr->content);
		ptr->content = old_content;
		free(old_content);
	}
}