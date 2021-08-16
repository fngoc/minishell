#include "../../minishell.h"

void	fd_check(t_file *file)
{
	if (file->g_fd >= 0)
		close(file->g_fd);
	dup2(4, 0);
	dup2(3, 1);
}
