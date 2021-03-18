#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

char **env_copy(char **env_original)
{
	char **env_copy;
	int len;
	int i;

	i = 0;
	len = arr_size(env_original);

	env_copy = (char**)malloc((sizeof(char*) * len) + 1);
	while (i < len)
	{
		env_copy[i] = ft_strdup(env_original[i]);
		i++;
	}

	return (env_copy);
}


