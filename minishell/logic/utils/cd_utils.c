/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:49:38 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/18 13:50:04 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		cd_error(int fd, char *dir, char *true_path)
{
	if (fd == -1)
	{
		fd = open(dir, O_RDONLY);
		if (fd == -1)
		{
			write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
			ft_putstr_fd("cd: ", 2);
			ft_putstr_fd(true_path, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			set_errno(1);
		}
		else
		{
			ft_putstr_fd("cd : ", 2);
			ft_putstr_fd(true_path, 2);
			ft_putstr_fd(": Not a directory\n", 2);
			set_errno(1);
		}
		return (0);
	}
	return (1);
}
