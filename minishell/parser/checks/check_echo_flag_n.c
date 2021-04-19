#include "../../minishell.h"

static	void	skipping_one_spaces(char **line)
{
	if (ft_istab(**line))
		++(*line);
}

static	void	double_pointer_movement(char **line)
{
	++(*line);
	++(*line);
}

int				check_echo_flag_n(char **line)
{
	skipping_more_spaces(line);
	while (**line != '\0')
	{
		skipping_one_spaces(line);
		if (**line == ';')
			return (2);
		if (**line == '-')
		{
			if (*(*line + 1) == 'n')
			{
				if (*(*line + 2) == ' ' || *(*line + 2) == '\0')
				{
					double_pointer_movement(line);
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
