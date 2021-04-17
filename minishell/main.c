/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:04:45 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/16 17:41:53 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	if (!(params = malloc(sizeof(g_list))))
		error("Allocated error", 11);
	params->env = env_copy(env);
	dup2(STDOUT_FILENO, 3);
	dup2(STDIN_FILENO, 4);
	parser();
	return (0);
}
