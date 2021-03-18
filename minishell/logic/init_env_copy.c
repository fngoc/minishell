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

//	env_copy = (char**)malloc((sizeof(char*) * len) + 1);
//	while (i < len)
//	{
//		env_copy[i] = ft_strdup(env_original[i]);
//		i++;
//	}
	while (++i < len)
	{
		ft_lstadd_back(&head, ft_lstnew(env_original[i]));
	}

	return (head);
}


