/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:33:03 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/18 14:07:50 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_null_value(char *content)
{
	int i;

	i = -1;
	while (content[++i])
	{
		if (content[i] == '=')
		{
			return (0);
		}
	}
	return (1);
}

void	print_env(void)
{
	t_list *tmp;

	tmp = g_params->env;
	while (g_params->env)
	{
		if (ft_strncmp("err", g_params->env->content, 3) == 0)
		{
			g_params->env = g_params->env->next;
			continue;
		}
		if (check_null_value(g_params->env->content) == 1)
		{
			g_params->env = g_params->env->next;
			continue;
		}
		ft_putstr_fd(g_params->env->content, 1);
		g_params->env = g_params->env->next;
		write(1, "\n", 1);
	}
	g_params->env = tmp;
	set_errno(0);
}
