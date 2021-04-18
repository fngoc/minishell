/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:19:59 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 15:20:00 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*single_quote(char **line)
{
	char	*str;

	str = NULL;
	++(*line);
	while (**line != '\'' && **line != '\0')
		str = ft_strjoin_char_free(str, *(*line)++);
	if (**line == '\0')
		error("Not a closed quote", 258);
	++(*line);
	if (**line != ' ' && **line != '\0')
	{
		if (**line == '\'')
			str = ft_strjoin_free_free(str, single_quote(line));
		else if (**line == '\"')
			str = ft_strjoin_free_free(str, double_quote(line));
		else
			str = ft_strjoin_free_free(str, without_quotation_marks(line));
	}
	return (str);
}
