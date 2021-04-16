#include "../../minishell.h"

/*
** what_is_redir: выставление флага редиректа.
*/

char	*what_is_redir(char *line, t_parser *p)
{
	char *tmp;

	tmp = NULL;
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
		return (line);
	}
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
				error("You can not write at the beginning of the command > or <", 258);
			return (++line);
		}
	}
	p->flag_redir = 2;
	return (line);
}
