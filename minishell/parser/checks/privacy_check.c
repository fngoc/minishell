#include "../../minishell.h"

/*
** counting_spaces: подсчет пробелов для
** будущего выделения памяти.
*/

static	void	counting_spaces(char *line, t_parser *p)
{
	p->coll_space = 0;
	while (*line != '\0')
	{
		if (*line == ' ')
			++p->coll_space;
		++line;
	}
}

/*
** checking_redir: проверка на синтаксис редиректов.
*/

static	void	checking_redir(char *line)
{
	if (line[ft_strlen(line) - 1] == '>' || line[ft_strlen(line) - 1] == '<')
		error("syntax error near unexpected token \'newline\'", 15);
}

/*
** privacy_check: проверка на все.
*/

void			privacy_check(char *line, t_parser *p)
{
	checking_single_quotes(line);
	checking_double_quotes(line);
	counting_spaces(line, p);
	checking_redir(line);
}
