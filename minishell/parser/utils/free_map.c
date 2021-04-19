#include "../../minishell.h"

void	free_map(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}
