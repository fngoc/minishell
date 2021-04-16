/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:31:56 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/16 17:32:36 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	char	*delet_first_exe(char *str)
{
	char *new_char;

	new_char = ++str;
	return (new_char);
}

int				err_exit(int err, char *command, char err_name, char *error_text)
{
	char *str_print;
	if (*command == '$')
	{
		if ((str_print = get_var_param(params->env, delet_first_exe(command))))
		{
			print_promt(str_print);
			ft_putstr_fd(": command not found\n", 2);
			set_errno(127);
		}
	}
	else if ((str_print = get_var_param(params->env, delet_first_exe(command))))
	{
		print_promt(str_print);
		ft_putstr_fd(": command not found\n", 2);
		set_errno(127);
	}
	else if (err_name == 'd')
	{
		print_promt(command);
		ft_putstr_fd(error_text, 2);
		set_errno(126);
	}
	else if (err_name == 'p')
	{
		print_promt(command);
		ft_putstr_fd(error_text, 2);
		set_errno(126);
	}

	else if (err_name == 'f')
	{
		print_promt(command);
		ft_putstr_fd(error_text, 2);
		set_errno(1);
	}
	else
	{
		print_promt(command);
		ft_putstr_fd(": command not found\n", 2);
		set_errno(127);
	}
	return (err);
}
