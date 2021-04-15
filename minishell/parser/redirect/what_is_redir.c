#include "../../minishell.h"

/*
** what_is_redir: выставление флага редиректа.
*/

char	*what_is_redir(char *line, t_parser *p)
{
    char *tmp;

	tmp = NULL;
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
			return (++line);
		}
	}
	p->flag_redir = 2;
	return (line);
}
