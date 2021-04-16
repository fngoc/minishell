#include "../minishell.h"

static	char	*delet_first_exe(char *str)
{
	char *new_char;

	new_char = ++str;
	return (new_char);
}

static int err_exit(int err, char *command, char err_name)
{
	char *str_print;
	if (*command == '$')
	{
		if ((str_print = get_var_param(params->env, delet_first_exe(command))))
		{
			print_promt(str_print);
			ft_putstr_fd(": command not found\n", 2);
			set_errno(127);
		}
	}
	else if ((str_print = get_var_param(params->env, delet_first_exe(command))))
	{
		print_promt(str_print);
		ft_putstr_fd(": command not found\n", 2);
		set_errno(127);
	}
	else if (err_name == 'd')
	{
		print_promt(command);
		ft_putstr_fd(": is a directory\n", 2);
		set_errno(126);
	}
	else if (err_name == 'p')
	{
		print_promt(command);
		ft_putstr_fd(": Permission denied\n", 2);
		set_errno(126);
	}

	else if (err_name == 'f')
	{
		print_promt(command);
		ft_putstr_fd(": No such file or directory\n", 2);
		set_errno(1);
	}
	else
	{
		print_promt(command);
		ft_putstr_fd(": command not found\n", 2);
		set_errno(127);
	}
	return (err);
}

char	**list_to_arr() {
	t_list *tmp;
	int i;

	tmp = params->env;
	char **arr;
	if (!(arr = ft_calloc(ft_lstsize(tmp) + 1, sizeof(char *))))
		error("Allocated error", 11);

	i = -1;
	while (tmp)
	{
		arr[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}

	return arr;
}

void 	exec_command(char *command, char **argv, char **env)
{
	pid_t pid;
	int err;

	pid = fork();
	if (pid == -1)
	{
		err = errno;
		set_errno(err);
	}

	if (pid == 0)
	{
		if(execve(command,argv, env) == -1)
		{
			err = errno;
			set_errno(err);
		}
		else
			set_errno(0);
		exit(0);
	}

	if (pid > 0)
		wait(&pid);
}

int check_executable(char *command)
{
	struct stat f;

	lstat(command, &f);

		if (f.st_mode & S_IFREG) {
			if (f.st_mode & S_IXUSR) {
				return 1;
			} else {
				return 0;
			}
		}

	return 0;
}

int 	exec(char *command, char **argv)
{
	int fd;
	char *str;
	char *str2;
	char **splitted;
	char **ev;
	char **tmp;
	char *tmp_join;

	ev = list_to_arr();
	fd = open(command, O_RDONLY);

	//check for permission denied or executable
	if (fd > 0)
	{
		if(ft_strchr(command, '/'))
		{
			if (check_executable(command)) {
				exec_command(command, argv, ev);
			}
			else
			{
				if (open(command, O_DIRECTORY) > 0)
					err_exit(126, command, 'd');
				else
					err_exit(126, command, 'p');
			}
			free_map(ev);
			close(fd);
			return(1);
		}
	}
	str2 = get_var_param(params->env, "PATH");
	if ((fd < 0 && ft_strchr(command, '/')) || str2 == NULL)
	{
		free_map(ev);
		err_exit(127, command, 'f');
		return(1);
	}
	splitted = ft_split(str2, ':');
	tmp = splitted;

		while (*splitted)
		{
			tmp_join = ft_strjoin("/", command);
			str = ft_strjoin(*splitted, tmp_join);
			fd = open(str, O_RDONLY);
			if (fd > 0)
			{
				exec_command(str, argv, ev);
				free(tmp_join);
				free(str);
				break;
			}
			close(fd);
			free(tmp_join);
			free(str);
			splitted++;
		}
		free_map(tmp);
		free_map(ev);
		if (fd == -1 && ft_strchr(command, '/'))
		{
			err_exit(127, command, 'f');
		}
		else if (fd == -1)
		{
			err_exit(127, command, ' ');
		}
	return 1;
}
