#include "../../parser/parser.h"

/*
** set_line: установка линиии в историю.
*/

void	set_line(char const *str, int fd, t_parser *p)
{
	char	*str_in_history;

	if (p->len_map >= 499)
		error("Memory overflow occurred, please restart the program");
	str_in_history = ft_strjoin(str, "\n");
	if (str_in_history[0] != '\n')
	{
		if (write(fd, str_in_history, ft_strlen(str_in_history))
			!= (int)ft_strlen(str_in_history))
			error("Failed to write a string to a file");
		p->map_history[++p->len_map] =
		ft_strdup(delet_last_char(str_in_history, 1));
		++p->step_history;
	}
	free(str_in_history);
}
