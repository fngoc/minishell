#include "../../minishell.h"

/*
** send_echo: отправка команды echo на выполнение.
*/

void	send_echo(char **map, t_parser *p)
{
	if (map[1] != NULL)
		ft_echo(map[1], p->flag_echo_n, p->coll_space);
	else if (map[1] == NULL)
		ft_putchar('\n');
}
