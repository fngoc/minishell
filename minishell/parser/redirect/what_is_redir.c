/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:42:22 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:47:51 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	char	*checking_flags(char *line, t_parser *p)
{
	if (p->flag_please == 1)
	{
		p->flag_please = 0;
		p->flag_redir = 3;
		return (line);
	}
	if (p->flag_please == 2)
	{
		p->flag_please = 0;
		p->flag_redir = 2;
		return (line);
	}
	if (p->flag_please_1 == 1)
	{
		p->flag_please_1 = 0;
		p->flag_redir = 1;
	}
	return (line);
}

/*
** what_is_redir: выставление флага редиректа.
*/

char			*what_is_redir(char *line, t_parser *p)
{
	char *tmp;

	tmp = NULL;
	if (p->flag_please == 1 || p->flag_please == 2
		|| p->flag_please_1 == 1)
		return (checking_flags(line, p));
	if (*line == '<')
	{
		p->flag_redir = 1;
		return (line);
	}
	else if (*line == '>')
	{
		tmp = line;
		++tmp;
		if (*tmp == '>')
		{
			p->flag_redir = 3;
			if (*(tmp + 1) == '>' || *(tmp + 1) == '<')
				error("Syntax error > or <", 258);
			return (++line);
		}
	}
	p->flag_redir = 2;
	return (line);
}
