#include "../../logic/logic.h"
#include "../../parser/parser.h"

/*
** set_line: установка линиии в историю.
*/

void set_line(char *str, int fd, t_parser *p)
{
	if (str[0] != '\n')
	{
		if (write(fd, str, ft_strlen(str)) != (int)ft_strlen(str))
			error("Failed to write a string to a file");
		p->map[++p->len_map] = ft_strdup(delet_backspace(str, 1));
		++p->step_history;
	}
	free(str);
}