/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:59:07 by drarlean          #+#    #+#             */
/*   Updated: 2021/04/16 18:01:45 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		print_chars(t_list *copy)
{
	int i;
	int check;

	i = -1;
	check = 0;
	if (ft_strncmp("err", copy->content, 3) == 0)
		return ;
	ft_putstr_fd("declare -x ", 1);
	while (copy->content[++i])
	{
		ft_putchar(copy->content[i]);
		if (copy->content[i] == '=' && check == 0)
		{
			write(1, "\"", 1);
			check = 1;
		}
		if ((check == 1 && copy->content[i + 1] == '\0'))
		{
			write(1, "\"", 1);
			check = 2;
		}
	}
	ft_putchar('\n');
}

static void		print_export(t_list *tmp_src, t_list *copy)
{
	copy = tmp_src;
	while (copy)
	{
		print_chars(copy);
		copy = copy->next;
	}
	copy = tmp_src;
	free_lst_map(&copy);
}

void			export(void)
{
	t_list *new;

	new = list_copy();
	sort_export(new);
}

void			swap_vars(char **tmp_str, t_list *new)
{
	*tmp_str = new->next->content;
	new->next->content = new->content;
	new->content = *tmp_str;
}

void			sort_export(t_list *new)
{
	t_list	*tmp_src;
	char	*tmp_str;
	int		len;
	int		i;
	int		j;

	tmp_src = new;
	len = ft_lstsize(new) - 1;
	i = -1;
	while (++i < len)
	{
		j = -1;
		new = tmp_src;
		while (++j < len)
		{
			if (ft_strncmp(new->content, new->next->content,
						ft_strlen(new->content)) > 0)
				swap_vars(&tmp_str, new);
			new = new->next;
		}
	}
	print_export(tmp_src, new);
	set_errno(0);
}
