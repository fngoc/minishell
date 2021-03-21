#include "../logic.h"
#include "../../parser/parser.h"
#include "../../libft/libft.h"

void	free_lst_map(t_list **lst)
{
	t_list *p;
	while (*lst)
	{
		p = (*lst)->next;
		free(*lst);
		free((*lst)->content);
		*lst = p;
	}
	*lst = NULL;
}
