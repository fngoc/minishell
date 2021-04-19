#include "../../minishell.h"

void	set_redir_map(t_parser *p)
{
	int i;

	i = -1;
	while (p->map_comand[++i] != NULL)
		;
	p->map_command_redir = ft_calloc(i + 1, sizeof(char **));
	i = -1;
	while (p->map_comand[++i] != NULL)
		p->map_command_redir[i] = ft_strdup(p->map_comand[i]);
}
