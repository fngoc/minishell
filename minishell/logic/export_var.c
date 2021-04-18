/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:40:48 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/18 14:07:50 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		set_error(char *var)
{
	t_list *tmp;

	tmp = g_params->env;
	tmp = get_env_list_pos(tmp, "err");
	free(tmp->content);
	tmp->content = ft_strdup(var);
}

static void		costyl_export(char *var, char **key, char **tmp_var)
{
	set_error(var);
	free(*key);
	free(*tmp_var);
}

static void		init_variables_export(char **tmp_var,
		t_list **tmp, char **key, char *var)
{
	*tmp_var = ft_strdup(var);
	*tmp = g_params->env;
	*key = get_key_by_full_param(*tmp_var);
}

static void		free_resources(char **tmp_var, char **key)
{
	free(*tmp_var);
	free(*key);
}

void			export_var(char *var)
{
	t_list	*tmp;
	char	*key;
	char	*tmp_var;

	init_variables_export(&tmp_var, &tmp, &key, var);
	if (ft_strcmp(key, "err") == 0)
	{
		costyl_export(var, &key, &tmp_var);
		return ;
	}
	if (validate_key(key) == 1)
	{
		not_valid_identifier(var, &key, &tmp_var);
		return ;
	}
	if (get_env_list_pos(g_params->env, key) == NULL)
	{
		if (*(tmp_var + ft_strlen(key) - 1) == '+')
			var[ft_strlen(key) - 1] = '\0';
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(var)));
		tmp = g_params->env;
	}
	else if (*(tmp_var + ft_strlen(key)) == '=')
		after_equals_sign(tmp, tmp_var, key);
	free_resources(&tmp_var, &key);
}
