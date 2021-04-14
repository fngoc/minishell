#include "../minishell.h"

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
** privacy_check: проверка на все.
*/

void			privacy_check(char *line, t_parser *p)
{
	checking_single_quotes(line);
	checking_double_quotes(line);
	counting_spaces(line, p);
}
