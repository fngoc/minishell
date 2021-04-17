/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:40:36 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:40:36 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	send_env(char **map)
{
	if (map[1] == NULL)
		print_env();
	else
	{
		ft_putstr_fd(map[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(map[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}
