#include "../minishell.h"

/*
** get_history_previous: взять предыдущую историю.
*/

void	get_history_previous(t_parser *p)
{
	free(p->str);
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map_history[p->step_history]);
	--p->step_history;
	write(1, p->str, ft_strlen(p->str));
}

/*
** get_history_next: взять следующую историю.
*/

void	get_history_next(t_parser *p)
{
	free(p->str);
	++p->step_history;
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map_history[p->step_history]);
	write(1, p->str, ft_strlen(p->str));
}
