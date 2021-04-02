#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static	char	*delet_first(char *str)
{
	char *new_char;

	new_char = ++str;
	return (new_char);
}

// Доделать такой пример: echo -n "fghn"

void 	ft_echo(char *str, int n_flag, int flag_param)
{
	t_list *tmp;

	tmp = params->env;
	char *str_print;

	str_print = NULL;

	if (n_flag == 0)
	{
		if (flag_param == 0)
		{
			ft_putstr_fd(str, 1);
			ft_putchar('\n');
		}
		else
		{
			if ((str_print = get_var_param(tmp, delet_first(str))))
				ft_putstr_fd(str_print, 1);
			ft_putchar('\n');
		}
	}
	else
	{
		if (flag_param == 0)
			ft_putstr_fd(str, 1);
		else
		{
			if ((str_print = get_var_param(tmp, delet_first(str))))
				ft_putstr_fd(str_print, 1);
		}
	}
}
