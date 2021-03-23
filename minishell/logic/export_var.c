#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

char 	*get_key_by_full_param(char *full_param)
{
	int length;
	char *ptr;
	char *key;
	int i;

	i = -1;
	length = 0;
	ptr = full_param;
	while (*full_param)
	{
		if (*full_param == '=')
			break;
		length++;
		full_param++;
	}
	full_param = ptr;
	key = (char*)malloc((sizeof(char) * length) + 1);
	while (++i < length)
	{
		if (*full_param == '=')
			break;
		key[i] = full_param[i];
	}
	return (key);
}

void 	export_var(char *var)
{
	t_list *tmp;
	char *key;

	tmp = params->env;
	key = get_key_by_full_param(var);
	if (get_var_param(tmp,key) == NULL)
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(var)));
		params->env = tmp;
	}
	else
	{
		tmp = get_env_list_pos(params->env, key);
		free(tmp->content);
		tmp->content = ft_strdup(var);
	}
	free(key);
}

