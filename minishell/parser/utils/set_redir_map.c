#include "../../parser/parser.h"

/*
** set_redir_map: устанавливаем мапу команд для редиректа.
*/

void	set_redir_map(t_parser *p, t_redir *r)
{
	int i;

	i = -1;
	while (p->map_comand[++i] != NULL)
		;
	r->map_command = ft_calloc(i + 1, sizeof(char **));
	i = -1;
	while (p->map_comand[++i] != NULL)
		r->map_command[i] = ft_strdup(p->map_comand[i]);
}
