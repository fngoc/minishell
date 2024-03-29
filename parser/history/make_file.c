#include "../../minishell.h"

int	make_file(void)
{
	int fd;

	if (!(fd = open("minishell_history", O_CREAT, S_IWRITE | S_IREAD)))
		error("Error when creating a file with the history", 1);
	if (!(fd = open("minishell_history", O_RDWR | O_TRUNC)))
		error("An error occurred while opening the history file", 1);
	return (fd);
}
