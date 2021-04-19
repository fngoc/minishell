#include "../../minishell.h"

void	write_cycle(char **line, char **str)
{
	while (**line != '\'' && **line != '\0')
		*str = ft_strjoin_char_free(*str, *(*line)++);
}
