#include "logic/logic.h"
#include "parser/parser.h"
#include "libft/libft.h"

/*
** main: запуск программы
*/

void	free_lst_map(t_list **lst)
{
	t_list *p;
	int i = 0;
	while (*lst)
	{
		p = (*lst)->next;
		free(*lst);
		*lst = p;
		i++;
	}
	printf("%d\n", i);
	*lst = NULL;
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	write(1, "Welcome to Minishell Fngoc and Drarlean!\n", 41);
	parser();

	params = malloc(sizeof (g_list));
	params->env = env_copy(env);

	printf("%s\n", pwd());
	cd("..");
	printf("%s\n", pwd());

    return 0;
}
