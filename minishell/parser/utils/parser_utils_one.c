/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:28:14 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 14:28:15 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	checking_repetitions(t_parser *p, char symbol)
{
	if (!(p->map_comand = ft_calloc(500, sizeof(char *))))
		error("Allocated error", 11);
	if (symbol == ';')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		error("You can not write at the beginning of the command ;", 258);
	}
	if (symbol == '|')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		error("You can not write at the beginning of the command |", 258);
	}
}

void	if_first_redir(t_file *file, t_parser *p)
{
	if (p->flag_redir == 1)
		back_redirect(file, p->file_name);
	else if (p->flag_redir == 2)
	{
		get_pipe_id(file);
		forward_redirect(file, p->file_name);
	}
	else if (p->flag_redir == 3)
	{
		get_pipe_id(file);
		double_redirect(file, p->file_name);
	}
	free(p->file_name);
}

void	if_second_redir(t_file *file, t_parser *p)
{
	if (p->flag_redir == 1)
	{
		back_redirect(file, p->file_name);
		pipe_process(p->map_command_redir, p, file);
	}
	else if (p->flag_redir == 2)
	{
		get_pipe_id(file);
		forward_redirect(file, p->file_name);
		pipe_process(p->map_command_redir, p, file);
	}
	else if (p->flag_redir == 3)
	{
		get_pipe_id(file);
		double_redirect(file, p->file_name);
		pipe_process(p->map_command_redir, p, file);
	}
	free(p->file_name);
	free_map(p->map_command_redir);
}

void	if_first_redir_flags(t_file *file, t_parser *p)
{
	if (p->flag_redir == 1)
	{
		back_redirect(file, p->file_name);
		pipe_process(p->map_command_redir, p, file);
	}
	else if (p->flag_redir == 2)
	{
		get_pipe_id(file);
		forward_redirect(file, p->file_name);
		pipe_process(p->map_command_redir, p, file);
	}
	else if (p->flag_redir == 3)
	{
		get_pipe_id(file);
		double_redirect(file, p->file_name);
		pipe_process(p->map_command_redir, p, file);
	}
	free(p->file_name);
	free_map(p->map_command_redir);
}

void	nullifying_flags(t_parser *p)
{
	p->flag_folder = 0;
	p->redir_here = 0;
	p->flag_redir = 0;
	p->flag_please = 0;
	p->flag_please_1 = 0;
}
