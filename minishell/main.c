#include "logic/logic.h"
#include "parser/parser.h"
#include "libft/libft.h"

/*
** main: запуск программы
*/

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	t_list *list;
    ft_putendl_fd("Welcome to Minishell Fngoc and Drarlean!", 1);
	list = env_copy(env);

	while (list)
	{
		printf("%s\n",(char *)list->content);
		list = list->next;
	}

    return 0;
}
