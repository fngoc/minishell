#include "../../minishell.h"

static	void	send_exit_norm(int flag, int flag_minus, char *str)
{
	if (flag == 0 && flag_minus == 1)
		error("exit", 255);
	else if (flag == 0)
		error("exit", ft_atoi(str));
	else
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(str, 2);
		error(": numeric argument required", 255);
	}
}

static	void	checking_and_nullifying(int *flag, int *i,
								int *flag_minus, char **map)
{
	*flag = 0;
	*i = -1;
	*flag_minus = 0;
	if (map[1] != NULL && map[2] != NULL)
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd("exit: ", 2);
		error("too many arguments", 255);
	}
}

void			send_exit(char **map)
{
	int flag;
	int i;
	int flag_minus;

	checking_and_nullifying(&flag, &i, &flag_minus, map);
	if (map[1] != NULL)
	{
		while (map[1][++i] != '\0')
		{
			if (map[1][0] == '-' && flag_minus == 0)
			{
				flag_minus = 1;
				++i;
			}
			if (!ft_isdigit(map[1][i]))
			{
				flag = 1;
				break ;
			}
		}
		send_exit_norm(flag, flag_minus, map[1]);
	}
	else
		error("exit", 0);
}
