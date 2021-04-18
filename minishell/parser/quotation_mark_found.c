/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_mark_found.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:29:19 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 11:46:08 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	set_in_map(int *i, char *name, t_parser *p)
{
	if (ft_strlen(name) > 0)
	{
		p->map_comand[++*i] = ft_strdup(name);
		free(name);
	}
	else
		p->map_comand[++*i] = NULL;
}

void			quotation_mark_found(t_parser *p, int *i,
							char **name, char **line)
{
	char what;

	if (p->previous_char != NULL && *p->previous_char == ' ')
		*name = NULL;
	what = **line;
	++(*line);
	if (what == '\'')
	{
		while (what == '\'' && **line != '\'' && **line != '\0')
			*name = ft_strjoin_char_free(*name, *(*line)++);
	}
	else
	{
		while ((**line != '\"' && **line != '\'') && **line != '\0')
			*name = ft_strjoin_char_free(*name, *(*line)++);
	}
	++(*line);
	if ((ft_istab(**line) || **line == '\0') && ft_strlen(*line) >= 0)
		set_in_map(i, *name, p);
	p->previous_char = NULL;
}
