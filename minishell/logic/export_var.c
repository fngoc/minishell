#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static int is_digit_in_key(const char *key)
{
	while (*key)
	{
		if (ft_isdigit(*key))
			return (1);
		key++;
	}
	return (0);
}

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
	char *tmp_var;

//	tmp_var = remove_double_quotes(var);
	tmp_var = ft_strdup(var);
	tmp = params->env;
	key = get_key_by_full_param(tmp_var);

	if (is_digit_in_key(key) == 1)
	{
		ft_putstr_fd("export: '", 1);
		ft_putstr_fd(var, 1);
		ft_putstr_fd("': not a valid identifier\n", 1);
	}
	// если не нашли переменную в енв, добавляем новую
	if (get_env_list_pos(params->env, key) == NULL)
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(var)));
		tmp = params->env;
	}
	// если есть символ равно в новой переменной, проvеряем что внутри
	else if (*(tmp_var + ft_strlen(key)) == '=')
	{
		tmp = get_env_list_pos(params->env, key);
		if (*(tmp_var + ft_strlen(key) + 1) != 0)
		{
			free(tmp->content);
			tmp->content = ft_strdup(tmp_var);
		}
		else
		{
			free(tmp->content);
			tmp->content = ft_strdup(key);
		}
	}
	free(tmp_var);
	free(key);

}
