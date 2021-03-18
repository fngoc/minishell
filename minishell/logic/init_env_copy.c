#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

char **env_copy(char **env_original)
{
	char **env_copy;
	int len;
	int i;

	i = 0;
	len = 0;
	while (env_original[len])
	{
		len++;
	}
	env_copy = malloc((sizeof(char) * len) + 1);
	while (env_copy[i])
	{
		env_copy[i] = ft_strdup(env_original[i]);
		i++;
	}


}


