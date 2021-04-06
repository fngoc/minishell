#include <signal.h>
#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//static void free_tmp(char **first, char **second)
//{
//	free_map(first);
//	free_map(second);
//}

static	char	*delet_first(char *str)
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
		if ((str_print = get_var_param(params->env, delet_first(command))))
		{
			write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
			ft_putstr_fd(str_print, 2);
			ft_putstr_fd(": command not found\n", 2);
		}
	}
	else if ((str_print = get_var_param(params->env, delet_first(command))))
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd(str_print, 2);
		ft_putstr_fd(": command not found\n", 2);
	}

	else if (err_name == 'p')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}

	else if (err_name == 'f')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	return (err);
}

char	**list_to_arr() {
	t_list *tmp;
	int i;

	tmp = params->env;
	char **arr;
	if (!(arr = ft_calloc(ft_lstsize(tmp) + 1, sizeof(char *))))
		error("allocated error");

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

	pid = fork();
	if (pid == -1)
	{
		errno_exit();
	}

	if (pid == 0)
	{
		if(execve(command,argv, env) == -1)
			errno_exit();
		exit(0);
	}
	if (pid > 0)
		wait(&pid);
}


int 	is_path_command(char **path, char *command)
{
	struct stat sb;
	char *str;
	char *tmp_join;

	while (*path)
	{
		tmp_join = ft_strjoin("/", command);
		str = ft_strjoin(*path, tmp_join);
		if (lstat(str, &sb) != -1) {
			if (sb.st_mode & S_IFREG) {
				if (sb.st_mode & S_IXUSR)
				{
					return 1;
				}
			}
		}
		path++;
		free(tmp_join);
		free(str);
	}
	return 0;
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
				err_exit(126, command, 'p');
			}
			free_map(ev);
			close(fd);
			return(1);
		}
	}
	str2 = get_var_param(params->env, "PATH");
		if ((fd < 0 && ft_strchr(command, '/')) ||
	str2 == NULL)
	{
		free_map(ev);
		err_exit(127, command, 'f');
		return(1);
	}
	splitted = ft_split(str2, ':');
	//tmp to free splitted
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
