#include "../../minishell.h"

/*
** send_exit_norm: функция для нормы.
*/

static	void	send_exit_norm(int flag, char *str)
{
	if (flag == 0)
		error("exit", ft_atoi(str));
	else
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(str, 2);
		error(": numeric argument required", 255);
	}
}

/*
** send_exit: выполнение команды exit.
*/

void			send_exit(char **map)
{
	int flag;
	int i;

	flag = 0;
	i = -1;
	if (map[1] != NULL && map[2] != NULL)
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd("exit: ", 2);
		error("too many arguments", 255);
	}
	else if (map[1] != NULL)
	{
		while (map[1][++i] != '\0')
		{
			if (!ft_isdigit(map[1][i]))
			{
				flag = 1;
				break ;
			}
		}
		send_exit_norm(flag, map[1]);
	}
	else
		error("exit", 0);
}
