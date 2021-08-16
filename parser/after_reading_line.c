#include "../minishell.h"

void	after_reading_line(t_parser *p, int fd, t_file *file)
{
	write(1, "\n", 1);
	p->step_history = p->len_map;
	set_line(p->str, fd, p);
	privacy_check(p->str, p);
	if (ft_strlen(p->str) > 0)
		parser_commands(p->str, p, file);
	p->flag_folder = 0;
	p->redir_here = 0;
	p->flag_redir = 0;
	p->flag_please = 0;
	p->flag_please_1 = 0;
	ft_bzero(p->str, ft_strlen(p->str));
}
