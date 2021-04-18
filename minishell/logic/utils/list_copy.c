/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:43:22 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/18 14:07:50 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_list	*list_copy(void)
{
	t_list *tmp;
	t_list *new;

	tmp = g_params->env;
	new = NULL;
	while (g_params->env)
	{
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(g_params->env->content)));
		g_params->env = g_params->env->next;
	}
	g_params->env = tmp;
	return (new);
}
