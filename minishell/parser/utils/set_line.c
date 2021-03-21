#include "../../logic/logic.h"
#include "../../parser/parser.h"

/*
** set_line: установка линиии в историю.
*/

void set_line(char *str, int fd)
{
	if (write(fd, str, ft_strlen(str)) != (int)ft_strlen(str))
		error("Failed to write a string to a file");
}