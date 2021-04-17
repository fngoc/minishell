/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:49:49 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:49:50 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** set_redir_map: устанавливаем мапу команд для редиректа.
*/

void	set_redir_map(t_parser *p)
{
	int i;

	i = -1;
	while (p->map_comand[++i] != NULL)
		;
	p->map_command_redir = ft_calloc(i + 1, sizeof(char **));
	i = -1;
	while (p->map_comand[++i] != NULL)
		p->map_command_redir[i] = ft_strdup(p->map_comand[i]);
}
