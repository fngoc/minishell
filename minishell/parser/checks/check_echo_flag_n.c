/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_echo_flag_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:35:11 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 15:03:33 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	void	double_pointer_movement(char **line)
{
	++(*line);
	++(*line);
}

int				check_echo_flag_n(char **line)
{
	while (**line != '\0')
	{
		if (ft_istab(**line))
			++(*line);
		if (**line == ';')
			return (2);
		if (**line == '-')
		{
			if (*(*line + 1) == 'n')
			{
				if (*(*line + 2) == ' ')
				{
					double_pointer_movement(line);
					return (1);
				}
				else
					return (0);
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}
