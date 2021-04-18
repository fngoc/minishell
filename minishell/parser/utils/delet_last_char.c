/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delet_last_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:07:10 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:07:11 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*delet_last_char(char *str, int coll_backspace)
{
	int len;

	coll_backspace += 2;
	len = ft_strlen(str) + 1;
	while (coll_backspace-- != 0)
		str[len--] = '\0';
	return (str);
}
