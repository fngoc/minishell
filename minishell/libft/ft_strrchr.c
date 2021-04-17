/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:53:55 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 12:55:30 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			tmp = &s[i];
		++i;
	}
	if (c == '\0')
		return (&((char *)s)[i]);
	if (tmp != NULL)
		return ((char *)tmp);
	return (NULL);
}
