#include "../minishell.h"

int unset(char *param)
{
	t_list **prev;
	t_list *temp;

	if (params->env == NULL)
		return 0;
	prev = &params->env;
	while ((*prev))
	{
		if(ft_strncmp((*prev)->content, param, ft_strlen(param)) == 0
		   && ((((int)((*prev)->content[ft_strlen(param)])) == '=') ||
		   ((int)((*prev)->content[ft_strlen(param)])) == '\0'))
		{
			temp = (*prev)->next;
			free((*prev)->content);
			free(*prev);
			*prev = temp;
			return 1;
		}
		prev = &((*prev)->next);
	}
	set_errno(0);
	return (0);
}
