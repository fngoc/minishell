#include <signal.h>
#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static void free_tmp(char **first, char **second)
{
	free_map(first);
	free_map(second);
}

static void err_exit(int err, char *command) {
	write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(err);
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


int 	exec(char *command, char **argv)
{
	int fd;
	char *str;
	char *str2;
	char **splitted;
	char **ev;
	char **tmp;
	int check;
	pid_t pid;
	char *tmp_join;
	struct stat sb;

	check = 0;
	pid = fork();

	if (pid == 0)
	{
		ev = list_to_arr();
		str2 = get_var_param(params->env, "PATH");
		if (!str2)
			return (-1);
		splitted = ft_split(str2, ':');

		tmp = splitted;
		if (command[0] == '.') {
			if (stat(command, &sb) == 0 && sb.st_mode & S_IXUSR) {
				check = execve(command, argv, ev);
				free_tmp(tmp, ev);
				exit(check);
			}
			else
			{
				write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
				ft_putstr_fd(command, 1);
				ft_putstr_fd(": Permission denied\n", 1);
				free_tmp(tmp, ev);
				exit(0);
			}
		}
		while (*splitted)
		{
			tmp_join = ft_strjoin("/", command);
			str = ft_strjoin(*splitted, tmp_join);
			fd = open(str, O_RDONLY);
			if (fd != -1) {

				check = execve(str, argv, ev);
			}

			close(fd);
			free(str);
			free(tmp_join);
			splitted++;
		}
		free_tmp(tmp, ev);
		if (fd == -1) {
			err_exit(check, command);
		}
		exit(check);
	}
	else if (pid == -1)
		error("failed to fork");
	wait(&pid);

	return (1);
}