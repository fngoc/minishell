/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delet_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:06:55 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:06:56 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*delet_first(char *str)
{
	char *new_char;
	char *tmp;

	tmp = str;
	new_char = ++str;
	free(tmp);
	return (new_char);
}
