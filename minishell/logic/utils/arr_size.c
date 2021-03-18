#include "../logic.h"
#include "../../parser/parser.h"
#include "../../libft/libft.h"

int arr_size(char **arr)
{
	int i = 0;

	while (arr[i])
		i++;
	return (i);
}
