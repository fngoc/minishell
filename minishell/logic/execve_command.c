#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

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
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		ev = list_to_arr();
		str2 = get_var_param(params->env, "PATH");
		if (!str2)
			return (-1);
		splitted = ft_split(str2, ':');
		char **tmp = splitted;
		while (*splitted)
		{
			str = ft_strjoin("/", command);
			str = ft_strjoin(*splitted, str);
//			free(splitted);
			fd = open(str, O_RDONLY);
			if (fd != -1) {
				execve(str, argv, ev);
			}
			free(str);
			splitted++;
		}
		free_map(tmp);
		free_map(ev);
		if (fd == -1)
			return -1;
	}
	else if (pid == -1)
		error("failed to fork");
	wait(&pid);
	return (1);
}