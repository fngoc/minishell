/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:32:36 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 14:32:37 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	void	single_norm(int *flag_in, int *open, int *coll, char c)
{
	if (*flag_in == 1 && c == '\"')
		*flag_in = 0;
	else if (*open == 0 && c == '\"')
		*flag_in = 1;
	if (*flag_in == 0 && c == '\'')
	{
		++*coll;
		*open = 1;
	}
	else if (*open == 1 && c == '\'')
	{
		++*coll;
		*open = 0;
	}
}

void			checking_single_quotes(char *line)
{
	int coll;
	int flag_in;
	int open;

	coll = 0;
	flag_in = 0;
	open = 0;
	while (*line != '\0')
	{
		if (*line == '\\')
		{
			++line;
			if (*line == '\'' || *line == '\"' || *line == '\\')
				++line;
			continue ;
		}
		single_norm(&flag_in, &open, &coll, *line);
		++line;
	}
	if (coll == 0)
		return ;
	if (coll % 2 != 0)
		error("Unclosed quotation single mark", 258);
}

static	void	double_norm(int *flag_in, int *open, int *coll, char c)
{
	if (*flag_in == 1 && c == '\'')
		*flag_in = 0;
	else if (*open == 0 && c == '\'')
		*flag_in = 1;
	if (*flag_in == 0 && c == '\"')
	{
		++*coll;
		*open = 1;
	}
	else if (*open == 1 && c == '\"')
	{
		++*coll;
		*open = 0;
	}
}

void			checking_double_quotes(char *line)
{
	int coll;
	int flag_in;
	int open;

	coll = 0;
	flag_in = 0;
	open = 0;
	while (*line != '\0')
	{
		if (*line == '\\')
		{
			++line;
			if (*line == '\'' || *line == '\"' || *line == '\\')
				++line;
			continue ;
		}
		double_norm(&flag_in, &open, &coll, *line);
		++line;
	}
	if (coll == 0)
		return ;
	if (coll % 2 != 0)
		error("Unclosed quotation double mark", 258);
}
