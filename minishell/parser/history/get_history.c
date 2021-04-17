/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:57:52 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:57:52 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	get_history_previous(t_parser *p)
{
	free(p->str);
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map_history[p->step_history]);
	--p->step_history;
	write(1, p->str, ft_strlen(p->str));
}

void	get_history_next(t_parser *p)
{
	free(p->str);
	++p->step_history;
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map_history[p->step_history]);
	write(1, p->str, ft_strlen(p->str));
}
