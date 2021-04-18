/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:40:47 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/18 11:21:19 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	send_echo(char **map, t_parser *p)
{
	if (map[1] != NULL)
		ft_echo(map[1], p->flag_echo_n, p->coll_space);
	else if (map[1] == NULL && p->flag_echo_n == 0)
		ft_putchar('\n');
}
