#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

t_list *env_copy(char **env_original)
{
	int len;
	int i;
	t_list	*head;

	head = NULL;
	i = -1;
	len = arr_size(env_original);
	while (++i < len)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(env_original[i])));
	}
	ft_lstadd_front(&head, ft_lstnew(ft_strdup("err=0")));

	return (head);
}

