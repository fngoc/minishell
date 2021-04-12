#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

void	redirect(char *file_name)
{
	int err;
	int file;

	if ((file = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		err = errno;
		set_errno(err);
	}
	dup2(file, 1);
}