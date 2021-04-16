/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:46:11 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/16 15:31:39 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int				minus_check(char **dir, char **old_content)
{
	if (**dir == '-')
	{
		*dir = get_var_param(params->env, "OLDPWD");
		if (*dir == NULL)
		{
			print_promt("cd: OLDPWD not set\n");
			free(*old_content);
			set_errno(1);
			return (0);
		}
	}
	return (1);
}

int				tilda_check(char **dir, char **old_content)
{
	char *tilda;

	if (**dir == '\0' || (**dir == '~' && *(*dir + 1) == '\0'))
	{
		*dir = get_var_param(params->env, "HOME");
		if (*dir == NULL)
		{
			print_promt("cd: HOME not set\n");
			free(*old_content);
			set_errno(1);
			return (0);
		}
	}
	if (**dir == '~')
	{
		tilda = ft_strjoin(get_var_param(params->env, "HOME"), *dir + 1);
		*dir = tilda;
		free(tilda);
	}
	return (1);
}

static void		null_check(char *old_content, t_list *start, char *param)
{
	char *tmp;

	if (ft_strcmp(param, "PWD") == 0)
		old_content = get_pwd();
	if (start == NULL)
	{
		tmp = change_value_by_key(param, old_content);
		export_var(tmp);
		free(tmp);
	}
	else
	{
		free(start->content);
		start->content = change_value_by_key(param, old_content);
	}
}

void			do_cd(char *dir, char **old_content)
{
	t_list *start;

	chdir(dir);
	start = get_env_list_pos(params->env, "PWD");
	null_check(*old_content, start, "PWD");
	free(start->content);
	start->content = change_value_by_key("PWD", get_pwd());
	start = get_env_list_pos(params->env, "OLDPWD");
	null_check(*old_content, start, "OLDPWD");
	free(*old_content);
}

void			cd(char *dir)
{
	char	*old_content;
	int		fd;
	char	*tmp;
	char	*true_path;

	true_path = dir;
	if (get_var_param(params->env, "PWD") == NULL)
	{
		tmp = ft_strjoin("PWD=", get_pwd());
		export_var(tmp);
		free(tmp);
	}
	old_content = ft_strdup(get_var_param(params->env, "PWD"));
	if (tilda_check(&dir, &old_content) == 0)
		return ;
	else if (minus_check(&dir, &old_content) == 0)
		return ;
	fd = open(dir, O_DIRECTORY);
	if (!cd_error(fd, dir, true_path))
	{
		free(old_content);
		return ;
	}
	else
		do_cd(dir, &old_content);
}
