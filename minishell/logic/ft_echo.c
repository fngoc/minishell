#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static	char	*delet_first(char *str)
{
	char *new_char;

	new_char = ++str;
	return (new_char);
}

void 	ft_echo(char **map, int n_flag, int flag_param, int flag_quotation_mark)
{
	t_list *tmp;
	int i;

	tmp = params->env;
	char *str_print;
	str_print = NULL;
	if (n_flag == 0)
		i = 0;
	else
		i = 1;
	while (map[++i] != NULL)
	{
		if (n_flag == 0)
		{
			if (flag_param == 0)
			{
				ft_putstr_fd(map[i], 1);
				ft_putchar('\n');
			}
			else
			{
				if ((str_print = get_var_param(tmp, delet_first(map[i]))))
					ft_putstr_fd(str_print, 1);
				else if (flag_quotation_mark || map[i] != NULL)
					ft_putstr_fd(map[i], 1);
				ft_putchar('\n');
			}
		}
		else
		{
			if (flag_param == 0)
				ft_putstr_fd(map[i], 1);
			else
			{
				if ((str_print = get_var_param(tmp, delet_first(map[i]))))
					ft_putstr_fd(str_print, 1);
				else if (flag_quotation_mark)
					ft_putstr_fd(map[i], 1);
			}
		}
	}
}
