#include "../../minishell.h"

char	*delet_first(char *str)
{
	char *new_char;
	char *tmp;

	tmp = str;
	new_char = ++str;
	free(tmp);
	return (new_char);
}
