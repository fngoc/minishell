#include "../../minishell.h"

void	get_pipe_id(t_file *file)
{
	int fd[2];

	if (pipe(fd) == -1)
	{
		set_errno(errno);
	}
	file->fd_stdin = fd[0];
	file->fd_stdout = fd[1];
}
