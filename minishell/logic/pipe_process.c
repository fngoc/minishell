#include "../minishell.h"

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
	if (file->g_fd != 0)
		close(file->g_fd);

	if ((file->g_fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		set_errno(2);
		return ;
	}

	file->fd_stdout = file->g_fd;
}

void 	back_redirect(t_file *file, char *file_name)
{
	if (file->g_fd != 0)
		close(file->g_fd);

	if ((file->g_fd = open(file_name, O_RDONLY, 0644)) == -1)
	{
		return ;
	}

	if (file->g_fd >= 0)
		file->fd_stdin = file->g_fd;
	file->g_fd = 0;
	dup2(file->fd_stdin, STDIN_FILENO);
	file->def_stdout = file->fd_stdout;
	dup2(STDOUT_FILENO, file->fd_stdout);
	file->back_redir = 1;
}

void 	double_redirect(t_file *file, char *file_name)
{
	if (file->g_fd != 0)
		close(file->g_fd);

	if ((file->g_fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
	{
		set_errno(errno);
		return ;
	}
	file->fd_stdout = file->g_fd;
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
		file->fd_stdout = file->def_stdout;
		set_errno(0);
	}
}
