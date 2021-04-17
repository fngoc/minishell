/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:07:24 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:07:39 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	error(char *str, int err)
{
	char *tmp;
	char *res;

	ft_putendl_fd(str, 2);
	tmp = ft_itoa(err);
	res = ft_strjoin("err=", tmp);
	export_var(res);
	free(tmp);
	free(res);
	exit(err);
}
