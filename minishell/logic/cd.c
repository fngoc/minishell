#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static	int cd_error(int fd, char *dir)
{
	if (fd == -1)
	{
		fd = open(dir, O_RDONLY);
		if (fd == -1)
		{
			write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
			ft_putstr_fd("cd: ", 2);
			ft_putstr_fd(dir, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		else
			{
				ft_putstr_fd("cd : ", 2);
				ft_putstr_fd(dir, 2);
				ft_putstr_fd(": Not a directory\n", 2);
			}
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
	{
		free(old_content);
		return;
	}
	else
	{
		chdir(dir);
		start = get_env_list_pos(params->env, "PWD");
		null_check(old_content, start, "PWD");
		free(start->content);
		start->content = change_value_by_key("PWD", get_pwd());
		start = get_env_list_pos(params->env, "OLDPWD");
		null_check(old_content, start, "OLDPWD");
		free(old_content);
	}
}
