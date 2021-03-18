#include "logic.h"

char	*get_path()
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	return cwd;
}
