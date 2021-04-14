#include "../minishell.h"

static void 	set_error(char *var)
{
	t_list *tmp;

	tmp = params->env;
	tmp = get_env_list_pos(tmp, "err");
	free(tmp->content);
	tmp->content = ft_strdup(var);
}

int		validate_key(char *key)
{
	int i;

	i = -1;

	if (ft_isdigit(key[0]))
		return (1);
	if (!ft_isalpha(key[0]))
	{
		if (key[0] != '_')
		{
			return (1);
		}
	}
	while (key[++i])
	{
		if (!ft_isalpha(key[i]))
		{
			if (!ft_isdigit(key[i]))
			{
				if (key[i] != '_')
					return (1);
			}
		}
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
	if (!(key = (char*)malloc((sizeof(char) * length) + 1)))
		error("Allocated error", 11);
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
	char *tmp_value;

	tmp_var = ft_strdup(var);
	tmp = params->env;
	key = get_key_by_full_param(tmp_var);
	if (ft_strcmp(key, "err") == 0)
	{
		set_error(var);
		free(key);
		free(tmp_var);
		return ;
	}
	if (validate_key(key) == 1)
	{
		print_promt("export: ");
		ft_putstr_fd("\'", 2);
		ft_putstr_fd(var, 2);
		ft_putstr_fd("\'", 2);
		ft_putendl_fd(" not a valid identifier", 2);
		set_errno(1);
		free(key);
		free(tmp_var);
		return ;
	}

	// если не нашли переменную в енв, добавляем новую
	if (get_env_list_pos(params->env, key) == NULL)
	{

		if (*(tmp_var + ft_strlen(key) - 1) == '+')
		{
			var[ft_strlen(key) - 1] = '\0';
		}
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(var)));
		tmp = params->env;
	}

	else if (*(tmp_var + ft_strlen(key)) == '=' &&
	*(tmp_var + ft_strlen(key) - 1) == '+')
	{
		tmp_value = ft_strdup(get_var_param(tmp, key));
		tmp = get_env_list_pos(params->env, key);
		if (*(tmp_var + ft_strlen(key) + 1) != 0)
		{
			free(tmp->content);
			tmp_var[ft_strlen(tmp_var) - 1] = '\0';
			tmp->content = ft_strjoin(tmp_var, tmp_value);
		}
		else
		{
			free(tmp->content);
			tmp->content = ft_strdup(key);
		}
		free(tmp_value);
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
