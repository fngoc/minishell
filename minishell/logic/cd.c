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

static void 	null_check(char *old_content, t_list *start, char *param)
{
	char *tmp;

	if (ft_strcmp(param, "PWD") == 0)
		old_content = get_pwd();
	if (start == NULL)
	{
		tmp = change_value_by_key(param, old_content);
		export_var(tmp);
		free(tmp);
	}
	else
	{
		free(start->content);
		start->content = change_value_by_key(param, old_content);
	}
}

void	cd(char *dir)
{
	char *old_content;
	int fd;
	t_list *start;

	old_content = ft_strdup(get_var_param(params->env, "PWD"));
	if (*dir == '\0')
		dir = get_var_param(params->env, "HOME");
	fd = open(dir, O_DIRECTORY);
	if (!cd_error(fd, dir))
		return ;
	else
	{
		chdir(dir);
		start = get_env_list_pos(params->env, "PWD");
		null_check(old_content, start, "PWD");
		start->content = change_value_by_key("PWD", get_pwd());
		start = get_env_list_pos(params->env, "OLDPWD");
		null_check(old_content, start, "OLDPWD");
		free(old_content);
	}
}