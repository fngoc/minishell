#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

char *get_command_path(int i)
{
	char *arr[7];

	arr[0] = "/.brew/bin";
	arr[1] = "/usr/local/bin";
	arr[2] = "/usr/bin";
	arr[3] = "/bin";
	arr[4] = "/usr/sbin";
	arr[5] = "/sbin";
	arr[6] = "/usr/local/munki";
	return (arr[i]);
}

void 	exec(char *command, char **argv, char **ev)
{
	int i = -1;
	int fd;
	char *str;

	while (++i < 7)
	{
		str = ft_strjoin("/",command);
		str = ft_strjoin(get_command_path(i),str);
		fd = open(str, O_RDONLY);
		if (fd)
			execve(str, argv, ev);
		free(str);
	}

}

