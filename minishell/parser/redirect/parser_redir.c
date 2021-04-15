#include "../../minishell.h"

/*
** parser_redir: парсим рудиректы.
*/

void	parser_redir(char **map_comand, t_parser *p, t_file *file, char c)
{
	if ((checking_folder(p->map_comand[0])) == 0)
	{
		ft_putstr_fd(p->map_comand[0], 2);
		ft_putendl_fd(": Is a directory", 2);
		return ;
	}
	if (!map_comand[0])
		error("syntax error near unexpected token \'newline\'", 15);
	p->file_name = ft_strdup(map_comand[0]);
	if (c == '<' || c == '>')
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
		p->flag_folder = 1;
	}
	else
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
		p->flag_folder = 1;
	}
	p->flag_redir = 0;
}
