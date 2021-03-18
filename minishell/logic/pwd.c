#include "logic.h"

char	*pwd()
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	return cwd;
}
