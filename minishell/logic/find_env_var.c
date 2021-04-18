/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:42:46 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/18 13:45:44 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var_param(t_list *env, char *param)
{
	int flag;

	if (ft_strlen(param) == 1 && !ft_strcmp(param, "?"))
		return (get_var_param(params->env, "err"));
	flag = 0;
	while (env)
	{
		if ((ft_strncmp(env->content, param, ft_strlen(param)) == 0)
		&& ((int)(env->content[ft_strlen(param)])) == '=')
		{
			flag = 1;
			break ;
		}
		env = env->next;
	}
	if (flag)
	{
		return (env->content + ft_strlen(param) + 1);
	}
	return (NULL);
}

char	*get_var_full_param(t_list *env, char *param)
{
	int flag;

	flag = 0;
	while (env)
	{
		if (ft_strncmp(env->content, param, ft_strlen(param)) == 0
				&& ((int)(env->content[ft_strlen(param)])) == '=')
		{
			flag = 1;
			break ;
		}
		env = env->next;
	}
	if (flag)
		return (env->content);
	return ("");
}

char	*change_value_by_key(char *key, char *value)
{
	char *str;
	char *str_tmp;

	str_tmp = ft_strjoin(key, "=");
	str = ft_strjoin(str_tmp, value);
	free(str_tmp);
	return (str);
}

t_list	*get_env_list_pos(t_list *env, char *param)
{
	int flag;

	flag = 0;
	while (env)
	{
		if (ft_strncmp(env->content, param, ft_strlen(param)) == 0
				&& (((int)(env->content[ft_strlen(param)])) == '=' ||
				((int)(env->content[ft_strlen(param)])) == '\0'))
		{
			flag = 1;
			break ;
		}
		env = env->next;
	}
	if (flag == 1)
		return (env);
	return (NULL);
}
