/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:22:59 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 14:28:45 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	calling_pipe(t_parser *p, t_file *file)
{
	get_pipe_id(file);
	pipe_process(p->map_comand, p, file);
}

static	int		separator_found(t_parser *p, t_file *file, char **line)
{
	if (**line == '|')
		calling_pipe(p, file);
	else if ((**line == '>' || **line == '<' || p->redir_here == 1)
										&& p->flag_redir == 0)
	{
		if (redirect_found(p, file, line) == 1)
			return (1);
	}
	else if (p->flag_folder == 1 && p->redir_here == 0 && p->flag_redir == 0)
	{
		if ((checking_folder(p->map_comand[0])) == 0)
		{
			ft_putstr_fd(p->map_comand[0], 2);
			ft_putendl_fd(": Is a directory", 2);
			return (1);
		}
		send_redir_two(p, file, line);
	}
	else if (p->flag_redir != 0)
		parser_redir(p->map_comand, p, file, **line);
	else
		send_command_execute(p->map_comand, p);
	checking_for_recursion(file, p, line);
	return (0);
}

static	void	beginning(int *i, char **name, char **line, t_parser *p)
{
	*i = -1;
	*name = NULL;
	p->previous_char = NULL;
	checking_repetitions(p, **line);
}

void			parser_commands(char *line, t_parser *p, t_file *file)
{
	char	*name;
	int		i;

	beginning(&i, &name, &line, p);
	while (*line != ';' && *line != '|' && *line != '<'
						&& *line != '>' && *line != '\0')
	{
		if (ft_istab(*line))
			p->previous_char = line++;
		else
		{
			branching(p, &i, &name, &line);
			if (p->map_comand[0] != NULL
				&& !ft_strcmp(p->map_comand[0], "echo"))
			{
				p->flag_echo_n = check_echo_flag_n(&line);
				if (p->flag_echo_n == 0 || p->flag_echo_n == 1)
					parser_echo(p, &line, &i);
				break ;
			}
		}
	}
	if (separator_found(p, file, &line) == 1)
		return ;
}
