#include "../parser.h"

/*
** make_file: создаем фаил с иcторией.
*/

int make_file(void)
{
	int fd;

	if (!(fd = open("minishell_history", O_CREAT, S_IWRITE | S_IREAD)))
		error("Error when creating a file with the history");
	if (!(fd = open("minishell_history", O_RDWR | O_TRUNC)))
		error("An error occurred while opening the history file");
	return (fd);
}