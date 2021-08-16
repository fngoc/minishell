#include "../../minishell.h"

void		not_valid_identifier(char *var, char **key, char **tmp_var)
{
	print_promt("export: ");
	ft_putstr_fd("\'", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd("\'", 2);
	ft_putendl_fd(" not a valid identifier", 2);
	set_errno(1);
	free(*key);
	free(*tmp_var);
}

int			validate_key(char *key)
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

char		*get_key_by_full_param(char *full_param)
{
	int		length;
	char	*ptr;
	char	*key;
	int		i;

	i = -1;
	length = 0;
	ptr = full_param;
	while (*full_param)
	{
		if (*full_param == '=')
			break ;
		length++;
		full_param++;
	}
	full_param = ptr;
	if (!(key = (char*)malloc((sizeof(char) * length) + 1)))
		error("Allocated error", 11);
	while (++i < length)
	{
		if (*full_param == '=')
			break ;
		key[i] = full_param[i];
	}
	return (key);
}

void		after_equals_sign(t_list *tmp, char *tmp_var, char *key)
{
	tmp = get_env_list_pos(g_params->env, key);
	if (*(tmp_var + ft_strlen(key) + 1) != 0)
	{
		free(tmp->content);
		tmp->content = ft_strdup(tmp_var);
	}
	else if (*(tmp_var + ft_strlen(key)) == '=')
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
