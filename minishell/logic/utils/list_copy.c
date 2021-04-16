/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:43:22 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/16 14:44:00 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_list	*list_copy(void)
{
	t_list *tmp;
	t_list *new;

	tmp = params->env;
	new = NULL;
	while (params->env)
	{
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(params->env->content)));
		params->env = params->env->next;
	}
	params->env = tmp;
	return (new);
}
