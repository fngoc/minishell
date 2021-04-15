#include "../../minishell.h"

/*
** checking_folder: проверка на папку для редиректа.
*/

int checking_folder(char *file)
{
	struct stat f;

	lstat(file, &f);
	if (S_ISDIR(f.st_mode))
		return (0);
	return (1);
}
