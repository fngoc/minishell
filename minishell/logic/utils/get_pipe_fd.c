/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:53:12 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/18 13:53:26 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
