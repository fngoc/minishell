#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void	pipe_process(char **argv, t_parser *p)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
	{
		errno_exit();
	}
	if ((pid = fork()) == -1)
		errno_exit();

	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		send_command_execute(argv, p);
//		exec(command, argv);
		close(fd[0]);
		close(fd[1]);
		close(STDOUT_FILENO);
		exit(0);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		wait(NULL);
		close(fd[0]);
	}
}
