#include "../../minishell.h"

void	skipping_more_spaces(char **line)
{
	if (**line == ' ')
	{
		while (**line == ' ')
			++(*line);
	}
}
