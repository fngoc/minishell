#include "../../minishell.h"

/*
** send_exec: отправка команд на выполнение.
*/

void	send_exec(char **map)
{
	int lvl;

	if (map[0] != NULL)
	{
		if (!ft_strcmp(map[0], "./minishell"))
		{
			lvl = ft_atoi(get_var_param(params->env, "SHLVL"));
			++lvl;
			export_var(ft_strjoin("SHLVL=", ft_itoa(lvl)));
		}
		if (!exec(map[0], map))
		{
			write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
			ft_putstr_fd(map[0], 2);
			ft_putstr_fd(": command not found\n", 2);
		}
	}
}
