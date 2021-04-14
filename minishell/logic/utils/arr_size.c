#include "../../minishell.h"

int arr_size(char **arr)
{
	int i = 0;

	while (arr[i])
		i++;
	return (i);
}
