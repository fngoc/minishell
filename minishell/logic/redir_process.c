#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//1. get_pipe_fd
//	int fd[2];
//	if (pipe(fd) == -1)
//		ft_error_errno_exit();
//	stdin_read = fd[0]
//	stdout_write = fd[1]
//
//2. > forward_redir
//	int fd;
//	if (fd != 0)
//		close(fd)
//	fd = openfile_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
//				error;
//	stdout_write = fd;

void	redirect(char *file_name)
{
	int err;
	int file;

	if ((file = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		err = errno;
		set_errno(err);
	}
	dup2(file, 1);
}