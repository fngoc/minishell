/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:13:22 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/16 18:17:50 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			forward_redirect(t_file *file, char *file_name)
{
	if (file->g_fd != 0)
		close(file->g_fd);
	if ((file->g_fd = open(
					file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		set_errno(2);
		return ;
	}
	file->fd_stdout = file->g_fd;
}

void			back_redirect(t_file *file, char *file_name)
{
	if ((file->g_fd = open(file_name, O_RDONLY, 0644)) == -1)
	{
		return ;
	}
	file->fd_stdin = file->g_fd;
	file->g_fd = 0;
	dup2(file->fd_stdin, STDIN_FILENO);
	file->def_stdout = file->fd_stdout;
}

void			double_redirect(t_file *file, char *file_name)
{
	if (file->g_fd != 0)
		close(file->g_fd);
	if ((file->g_fd = open(
					file_name, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
	{
		set_errno(errno);
		return ;
	}
	file->fd_stdout = file->g_fd;
}

static	void	fork_errno(void)
{
	int err;

	err = errno;
	set_errno(err);
}

void			pipe_process(char **argv, t_parser *p, t_file *file)
{
	pid_t pid;

	if ((pid = fork()) == -1)
		fork_errno();
	else if (pid == 0)
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
