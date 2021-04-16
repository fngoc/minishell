#include "../../minishell.h"

/*
** check_echo_flag_n: проверка на -n.
*/

int	check_echo_flag_n(char **line)
{
	while (**line != '\0')
	{
		if (ft_istab(**line))
			++(*line);
		if (**line == ';')
			return (2);
		if (**line == '-')
		{
			// ++(*line);
			if (*(*line + 1) == 'n')
			{
				// ++(*line);
				if (*(*line + 2) == ' ')
				{
					++(*line);
					++(*line);
					return (1);
				}
				else
					return (0);
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}
