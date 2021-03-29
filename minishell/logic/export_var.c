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
	if (get_env_list_pos(tmp, key) == NULL)
	{
		if (var[ft_strlen(key) + 1] == '\0')
			ft_lstadd_back(&tmp, ft_lstnew(remove_double_quotes(key)));
		else
			ft_lstadd_back(&tmp, ft_lstnew(remove_double_quotes(var)));
		params->env = tmp;
	}
	else
	{
		tmp = get_env_list_pos(params->env, key);
		free(tmp->content);
		if (*(key + 1) == '=') {
			tmp->content = remove_double_quotes(key);
			free(key);
		}

		else if (*(key + 1) == '\0')
			return;
		else {
			tmp->content = remove_double_quotes(var);
			free(key);
		}
	}

}

char  	*remove_double_quotes(const char *var)
{
	char *content;
	int len;
	int i;

	len = 0;
	i = -1;
	while (var[++i])
	{
		if (*var != '\"')
			len++;
	}
	content = (char *)malloc( len + 1);
	i = -1;
	int j = 0;
	while (++i < len)
	{
		if (var[i] != '\"')
		{
			content[j] = var[i];
			j++;
		}
	}
	return (content);
}

