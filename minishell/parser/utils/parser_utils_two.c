/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:28:21 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 14:29:29 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	checking_for_recursion(t_file *file, t_parser *p, char **line)
{
	free_map(p->map_comand);
	if (**line == ';')
		nullifying_flags(p);
	if (ft_strlen(*line) > 1)
	{
		if (**line == '>')
		{
			if (*(*line + 1) == '>')
			{
				++*line;
				p->flag_please = 1;
			}
			else
				p->flag_please = 2;
		}
		if (**line == '<')
			p->flag_please_1 = 1;
		parser_commands(++*line, p, file);
	}
	p->flag_echo_n = 0;
	p->flag_quotation_mark = 0;
}

void	branching(t_parser *p, int *i, char **name, char **line)
{
	if (*i >= 499)
		error("Exceeded the limit on the \
			number of commands per line", 11);
	if (**line == '\"' || **line == '\'')
		quotation_mark_found(p, i, name, line);
	else
		quotation_mark_not_found(p, i, name, line);
}

void	send_redir_one(t_parser *p, t_file *file, char symbol)
{
	if (!p->map_comand[0])
		error("syntax error near unexpected token \'newline\'", 15);
	p->file_name = ft_strdup(p->map_comand[0]);
	if (symbol == '<' || symbol == '>')
		if_first_redir(file, p);
	else
		if_second_redir(file, p);
	p->flag_folder = 0;
	p->redir_here = 0;
}

void	send_redir_two(t_parser *p, t_file *file, char **line)
{
	if (!p->map_comand[0])
		error("syntax error near unexpected token \'newline\'", 15);
	p->file_name = ft_strdup(p->map_comand[0]);
	*line = what_is_redir(*line, p);
	if_first_redir_flags(file, p);
}

int		redirect_found(t_parser *p, t_file *file, char **line)
{
	p->redir_here = 1;
	*line = what_is_redir(*line, p);
	if (p->flag_folder == 1)
	{
		if ((checking_folder(p->map_comand[0])) == 0)
		{
			ft_putstr_fd(p->map_comand[0], 2);
			ft_putendl_fd(": Is a directory", 2);
			return (1);
		}
		send_redir_one(p, file, **line);
	}
	else
		set_redir_map(p);
	return (0);
}
