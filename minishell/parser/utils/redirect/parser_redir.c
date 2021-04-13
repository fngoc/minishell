#include "../../parser.h"

/*
** parser_redir: парсим рудиректы.
*/

void	parser_redir(char **map_comand, t_parser *p, t_file *file, t_redir *r)
{
	p->second_arg_redir = ft_strdup(map_comand[0]);
	map_comand[0] = ft_strdup(p->first_arg_redir);
	if (p->flag_redir == 1)
	{
		back_redirect(file, p->second_arg_redir);
		pipe_process(r->map_command, p, file);
	}
	if (p->flag_redir == 2)
	{
		get_pipe_id(file);
		forward_redirect(file, p->second_arg_redir);
		pipe_process(r->map_command, p, file);
	}
	if (p->flag_redir == 3)
	{
		get_pipe_id(file);
		double_redirect(file, p->second_arg_redir);
		pipe_process(r->map_command, p, file);
	}
	free(p->first_arg_redir);
	free(p->second_arg_redir);
	free_map(r->map_command);
	p->flag_redir = 0;
}
