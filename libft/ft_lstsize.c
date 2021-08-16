#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*p;

	i = 0;
	p = lst;
	while (p != NULL)
	{
		p = p->next;
		++i;
	}
	return (i);
}
