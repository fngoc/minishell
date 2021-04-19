#include "../../minishell.h"

int	checking_folder(char *file)
{
	struct stat f;

	lstat(file, &f);
	if (S_ISDIR(f.st_mode))
		return (0);
	return (1);
}
