/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:41:14 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:41:14 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** send_pwd: отправка команды pwd на выполнение.
*/

static	void	send_pwd(void)
{
	print_pwd();
	write(1, "\n", 1);
}

/*
** send_cd: отправка команды cd на выполнение.
*/

static	void	send_cd(char **map)
{
	if (map[1] != NULL && !ft_strcmp(map[1], ".."))
		cd("..");
	else if (map[1] == NULL || !ft_strcmp(map[1], "~"))
		cd("~");
	else if (map[1] != NULL)
		cd(map[1]);
}

/*
** send_export: отправка команды export на выполнение.
*/

static	void	send_export(char **map)
{
	if (map[1] != NULL)
		export_var(map[1]);
	else
		export();
}

/*
** send_unset: отправка команды unset на выполнение.
*/

static	void	send_unset(char **map)
{
	if (map[1] != NULL)
		unset(map[1]);
}

/*
** send_command_execute: отправка команд на выполнение.
*/

void			send_command_execute(char **map_comand, t_parser *p)
{
	if (map_comand[0] == NULL)
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (!ft_strcmp(map_comand[0], "$?"))
		send_question_mark();
	else if (!ft_strcmp(map_comand[0], "pwd"))
		send_pwd();
	else if (!ft_strcmp(map_comand[0], "cd"))
		send_cd(map_comand);
	else if (!ft_strcmp(map_comand[0], "export"))
		send_export(map_comand);
	else if (!ft_strcmp(map_comand[0], "unset"))
		send_unset(map_comand);
	else if (!ft_strcmp(map_comand[0], "env"))
		send_env(map_comand);
	else if (!ft_strcmp(map_comand[0], "exit"))
		send_exit(map_comand);
	else if (!ft_strcmp(map_comand[0], "echo"))
		send_echo(map_comand, p);
	else
		send_exec(map_comand);
}
