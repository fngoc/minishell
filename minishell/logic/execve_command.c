#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	exec(char *command, char **argv, char **ev)
{
	int fd;
	char *str;
	char *str2;
	char **splitted;
	pid_t pid;

	pid = fork();

	if (pid == 0) {
		str2 = get_var_param(params->env, "PATH");
		if (!str2)
			return;
		splitted = ft_split(str2, ':');

		while (*splitted) {
			str = ft_strjoin("/", command);

			str = ft_strjoin(*splitted, str);
			fd = open(str, O_RDONLY);
			if (fd)
				execve(str, argv, ev);
			free(str);
			splitted++;
		}
		free_map(splitted);
	}
}

