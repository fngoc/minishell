/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_echo_n_check_start.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:58:26 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/18 11:20:03 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	void	double_echo_n_check(char **line, t_parser *p)
{
	skipping_more_spaces(line);
	if (**line == '-' && *(*line + 1) == 'n'
		&& *(*line + 2) == ' ' && p->flag_echo_n == 1)
	{
		++(*line);
		++(*line);
	}
	else if (**line == '-' && *(*line + 1) == 'n'
		&& *(*line + 2) == '\0' && p->flag_echo_n == 1)
	{
		++(*line);
		++(*line);
	}
}

void			double_echo_n_check_start(char **line, t_parser *p)
{
	skipping_more_spaces(line);
	while (**line == '-' && *(*line + 1) == 'n'
		&& (*(*line + 2) == ' ' || *(*line + 2) == '\0') && p->flag_echo_n == 1)
	{
		double_echo_n_check(line, p);
		skipping_more_spaces(line);
	}
}
