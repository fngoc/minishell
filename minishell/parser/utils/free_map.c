#include "../parser.h"

/*
** get_history_previous: взять предыдущую историю.
*/

void free_map(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}
