#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void 	ft_echo(char **map, int n_flag, int flag_param, int flag_quotation_mark)
{
	(void)flag_quotation_mark;
	t_list *tmp;
	char *str_print;
	int i;
	int j;

	tmp = params->env;
	if (n_flag == 0)
		i = 0;
	else
		i = 1;
	while (map[++i] != NULL)
	{
		if (flag_param == 0)
			ft_putstr_fd(map[i], 1);
		else
		{
			j = 0;
			while (map[i][j] != '\0')
			{
				if (map[i][j] != '$')
					ft_putchar(map[i][j++]);
				else if (map[i][j] == '$')
				{
					++j;
					str_print = NULL;
					while (!ft_istab(map[i][j]) && map[i][j] != '\0')
						str_print = ft_strjoin_char_free(str_print, map[i][j++]);
					free(str_print);
					if ((str_print = get_var_param(tmp, str_print)))
						ft_putstr_fd(str_print, 1);
				}
			}
		}
		ft_putchar(' ');
	}
	if (n_flag == 0)
		ft_putchar_fd('\n', 1);
}
