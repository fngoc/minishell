#include "../../minishell.h"

void	send_env(char **map)
{
	if (map[1] == NULL)
		print_env();
	else
	{
		ft_putstr_fd(map[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(map[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}
