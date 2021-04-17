/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:12:21 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:12:22 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** is_arrow: проверка.
*/

int	is_arrow(char const *buf)
{
	return (!(ft_strcmp(buf, "\e[C") && ft_strcmp(buf, "\e[B")
			&& ft_strcmp(buf, "\e[D") && ft_strcmp(buf, "\177")
			&& ft_strcmp(buf, "\e[A")));
}
