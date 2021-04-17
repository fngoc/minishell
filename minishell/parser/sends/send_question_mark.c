/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_question_mark.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:16:58 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:16:58 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	send_question_mark(void)
{
	write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(get_var_param(params->env, "?"), 2);
	ft_putstr_fd("\n", 2);
}
