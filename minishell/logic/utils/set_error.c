/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:44:46 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/16 14:45:43 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_errno(int err)
{
	char *tmp;
	char *res;

	tmp = ft_itoa(err);
	res = ft_strjoin("err=", tmp);
	export_var(res);
	free(tmp);
	free(res);
}
