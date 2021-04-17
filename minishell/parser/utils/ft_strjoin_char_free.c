/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:08:42 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:08:42 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strjoin_char_free(char *s1, char c)
{
	char	*p;
	int		i;
	int		j;

	p = malloc(ft_strlen(s1) + 2);
	i = 0;
	j = 0;
	if (p == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		p[i] = s1[i];
		++i;
	}
	p[i] = c;
	free(s1);
	p[++i] = '\0';
	return (p);
}
