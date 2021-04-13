#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//TODO errors
void 	get_pipe_id(t_file *file)
{
	int fd[2];

	if (pipe(fd) == -1)
	{
		set_errno(errno);
	}
	file->fd_stdin = fd[0];
	file->fd_stdout = fd[1];
}

void 	forward_redirect(t_file *file, char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		set_errno(2);
		return ;
	}
	file->fd_stdout = fd;
}

void 	back_redirect(t_file *file, char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY, 0644)) == -1)
	{
		set_errno(errno);
		return ;
	}
	if (file->fd_stdin >= 0)
		file->fd_stdin = fd;

	dup2(file->fd_stdin, STDIN_FILENO);
}

void 	double_redirect(t_file *file, char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
	{
		set_errno(errno);
		return ;
	}
	file->fd_stdout = fd;
}

void	pipe_process(char **argv, t_parser *p, t_file *file)
{
	pid_t pid;
	int err;

	if ((pid = fork()) == -1)
	{
		err = errno;
		set_errno(err);
	}

	if (pid == 0)
	{
		dup2(file->fd_stdout, STDOUT_FILENO);
		send_command_execute(argv, p);
		close(file->fd_stdin);
		close(file->fd_stdout);
		close(STDOUT_FILENO);
		set_errno(0);
		exit(0);
	}
	else
	{
		dup2(file->fd_stdin, STDIN_FILENO);
		close(file->fd_stdout);
		wait(NULL);
		close(file->fd_stdin);
		set_errno(0);
	}
	wait(NULL);
}
