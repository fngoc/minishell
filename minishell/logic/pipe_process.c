#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//TODO errors
void	pipe_process(char **argv, t_parser *p)
{
	int fd[2];
	pid_t pid;
	int err;

	if (pipe(fd) == -1)
	{
		err = errno;
		set_errno(err);
	}
	if ((pid = fork()) == -1)
	{
		err = errno;
		set_errno(err);
	}

	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		send_command_execute(argv, p);
		close(fd[0]);
		close(fd[1]);
		close(STDOUT_FILENO);
		set_errno(0);
		exit(0);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		wait(NULL);
		close(fd[0]);
		set_errno(0);
	}
}
