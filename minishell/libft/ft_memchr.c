/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:21:26 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 12:53:59 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const char	*tmp;

	tmp = arr;
	while (n-- != 0)
	{
		if (*tmp != c)
			tmp++;
		else
			return ((char *)tmp);
	}
	return (NULL);
}
