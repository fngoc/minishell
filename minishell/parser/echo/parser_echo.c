/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:17:13 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 15:18:37 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	void	checking_quotation_marks_two(char **name,
								char **line, int *flag_mark)
{
	if ((**line == '\'' || **line == '\"') && *flag_mark == 1)
		*flag_mark = 0;
	else if ((**line == '\'' || **line == '\"'))
		*flag_mark = 1;
	*name = ft_strjoin_char_free(*name, **line);
	++(*line);
}

static	void	checking_quotation_marks_one(char **name,
								char **line, int *flag_mark)
{
	*name = NULL;
	if (**line == '\'' || **line == '\"')
	{
		*flag_mark = 1;
		*name = ft_strjoin_char_free(*name, **line);
		++(*line);
	}
}

static	void	send_in_map(char **name, int *i, t_parser *p)
{
	if (ft_strlen(*name) == 0)
		error("Syntax error near unexpected token", 258);
	p->map_comand[++*i] = ft_strdup(*name);
	free(*name);
}

static	void	double_pointer_movement_check(char **line, t_parser *p)
{
	if (**line == '-' && *(*line + 1) == 'n'
		&& *(*line + 2) == ' ' && p->flag_echo_n == 1)
	{
		++(*line);
		++(*line);
	}
}

void			parser_echo(t_parser *p, char **line, int *i)
{
	char	*name;
	int		flag_mark;

	flag_mark = 0;
	if (!**line)
	{
		p->map_comand[++*i] = NULL;
		return ;
	}
	checking_quotation_marks_one(&name, line, &flag_mark);
	while ((**line != ';' && **line != '|' && **line != '>'
	&& **line != '<' && **line != '\0') || flag_mark == 1)
	{
		double_pointer_movement_check(line, p);
		if (**line == '\\')
		{
			name = ft_strjoin_char_free(name, *(*line)++);
			name = ft_strjoin_char_free(name, *(*line)++);
			continue ;
		}
		checking_quotation_marks_two(&name, line, &flag_mark);
		if (**line == '\0')
			break ;
	}
	send_in_map(&name, i, p);
}
