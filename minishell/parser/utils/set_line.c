#include "../../logic/logic.h"
#include "../../parser/parser.h"

/*
** set_line: установка линиии в историю.
*/

void set_line(char *str, int fd, char **map, int *len_map)
{
	if (str[0] != '\n')
	{
		if (write(fd, ft_strjoin(str, "\n"), ft_strlen(str)) != (int)ft_strlen(str))
			error("Failed to write a string to a file");
		map[++*len_map] = ft_strdup(delet_backspace(str, 1));
	}
	// free(str);
}