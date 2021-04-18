/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:46:52 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/18 13:47:22 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*env_copy(char **env_original)
{
	int		len;
	int		i;
	t_list	*head;

	head = NULL;
	i = -1;
	len = arr_size(env_original);
	while (++i < len)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(env_original[i])));
	}
	ft_lstadd_front(&head, ft_lstnew(ft_strdup("err=0")));
	return (head);
}
