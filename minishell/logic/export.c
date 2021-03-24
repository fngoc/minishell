#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static void 	print_chars(t_list *copy, int equal_sign)
{
	int i;

	i = 0;
	ft_putstr_fd("declare -x ", 1);
	while (copy->content[i])
	{
		ft_putchar(copy->content[i]);
		if ((copy->content[i] == '=' && equal_sign == 0) ||
			copy->content[i + 1] == '\0')
		{
			printf("\"");
			equal_sign = 1;
		}
		i++;
	}
	ft_putchar('\n');
}

static void		print_export(t_list *tmp_src, t_list *copy)
{
	int equal_sign;

	copy = tmp_src;
	while (copy)
	{
		equal_sign = 0;
		print_chars(copy, equal_sign);
		copy = copy->next;
	}
	copy = tmp_src;
	free_lst_map(&copy);
}

void 			export()
{
	t_list *new;

	new = list_copy();
	sort_export(new);
}

void			sort_export(t_list *new)
{
	t_list *tmp_src;
	char *tmp_str;
	int len;
	int i;
	int j;

	tmp_src = new;
	len = ft_lstsize(new) - 1;
	i = -1;
	while (++i < len)
	{
		j = -1;
		new = tmp_src;
		while (++j < len)
		{
			if (ft_strncmp(new->content, new->next->content, ft_strlen(new->content)) > 0)
			{
				tmp_str = new->next->content;
				new->next->content = new->content;
				new->content = tmp_str;
			}
			new = new->next;
		}
	}
	print_export(tmp_src, new);
}
