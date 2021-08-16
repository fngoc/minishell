#include "../minishell.h"

char		**list_to_arr(void)
{
	t_list	*tmp;
	int		i;
	char	**arr;

	tmp = g_params->env;
	if (!(arr = ft_calloc(ft_lstsize(tmp) + 1, sizeof(char *))))
		error("Allocated error", 11);
	i = -1;
	while (tmp)
	{
		arr[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (arr);
}

void		exec_command(char *command, char **argv, char **env)
{
	pid_t	pid;
	int		err;

	pid = fork();
	if (pid == -1)
	{
		err = errno;
		set_errno(err);
	}
	if (pid == 0)
	{
		if (execve(command, argv, env) == -1)
		{
			err = errno;
			set_errno(err);
		}
		else
			set_errno(0);
		exit(err);
	}
	if (pid > 0)
	{
		wait(&err);
		set_errno(err >> 8);
	}
}

int			check_executable(char *command)
{
	struct stat f;

	lstat(command, &f);
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	return (0);
}

int			permission_denied(char *command, char **argv, char **ev, int fd)
{
	if (ft_strchr(command, '/'))
	{
		if (check_executable(command))
		{
			exec_command(command, argv, ev);
		}
		else
		{
			if (open(command, O_DIRECTORY) > 0)
				err_exit(126, command, 'd', ": is a directory\n");
			else
				err_exit(126, command, 'p', ": Permission denied\n");
		}
		free_map(ev);
		close(fd);
		return (1);
	}
	return (0);
}

int			exec(char *command, char **argv)
{
	int		fd;
	char	*path_non_splitted;
	char	**ev;

	ev = list_to_arr();
	fd = open(command, O_RDONLY);
	if (fd > 0)
	{
		if (permission_denied(command, argv, ev, fd) == 1)
			return (1);
	}
	path_non_splitted = get_var_param(g_params->env, "PATH");
	if ((fd < 0 && ft_strchr(command, '/')) || path_non_splitted == NULL)
	{
		free_map(ev);
		err_exit(127, command, 'f', ": No such file or directory\n");
		return (1);
	}
	fd = execve_path(path_non_splitted, argv, ev, command);
	free_map(ev);
	if (fd == -1 && ft_strchr(command, '/'))
		err_exit(127, command, 'f', ": No such file or directory\n");
	else if (fd == -1)
		err_exit(127, command, ' ', "");
	return (1);
}
