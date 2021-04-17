/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_folder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:56:34 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:56:40 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** checking_folder: проверка на папку для редиректа.
*/

int	checking_folder(char *file)
{
	struct stat f;

	lstat(file, &f);
	if (S_ISDIR(f.st_mode))
		return (0);
	return (1);
}
