/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:57:24 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:57:25 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	make_file(void)
{
	int fd;

	if (!(fd = open("minishell_history", O_CREAT, S_IWRITE | S_IREAD)))
		error("Error when creating a file with the history", 1);
	if (!(fd = open("minishell_history", O_RDWR | O_TRUNC)))
		error("An error occurred while opening the history file", 1);
	return (fd);
}
