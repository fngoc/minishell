/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:40:47 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:40:48 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** send_echo: отправка команды echo на выполнение.
*/

void	send_echo(char **map, t_parser *p)
{
	if (map[1] != NULL)
		ft_echo(map[1], p->flag_echo_n, p->coll_space);
	else if (map[1] == NULL)
		ft_putchar('\n');
}
