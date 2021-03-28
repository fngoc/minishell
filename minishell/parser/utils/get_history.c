#include "../../parser/parser.h"

/*
** get_history_previous: взять предыдущую историю.
*/

void get_history_previous(t_parser *p)
{
	free(p->str);
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map_history[p->step_history]);
	// if (p->flag_step_history_previou == 0)
	// {
		--p->step_history;
	// 	p->flag_step_history_previou = 0;
	// 	p->flag_step_history_next = 1;
	// }
	// else
	// {
	// 	p->step_history -= 2;
	// 	p->flag_step_history_previou = 0;
	// }
	write(1, p->str, ft_strlen(p->str));
}

/*
** get_history_next: взять следующую историю.
*/

void get_history_next(t_parser *p)
{
	free(p->str);
	// if (p->flag_step_history_next == 0)
	// {
		++p->step_history;
	// 	p->flag_step_history_previou = 1;
	// 	p->flag_step_history_next = 0;
	// }
	// else
	// {
	// 	p->step_history += 2;
	// 	p->flag_step_history_next = 0;
	// }
	if (p->step_history <= p->len_map)
		p->str = ft_strdup(p->map_history[p->step_history]);
	write(1, p->str, ft_strlen(p->str));
}
