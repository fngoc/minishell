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

	params = malloc(sizeof(g_list));

    ft_putendl_fd("Welcome to Minishell Fngoc and Drarlean!", 1);
	params->env = env_copy(env);
	printf("%s\n",env_var_param(params->env, "PWD"));
	cd("..");
	printf("%s\n",env_var_param(params->env, "PWD"));

	return 0;

	t_list *list;
    ft_putendl_fd("Welcome to Minishell Fngoc and Drarlean!", 1);
	parser();
	// char **copy = env_copy(env);
	// printf("%s\n", find_env_var(copy, "OLDPWD"));
    return 0;
}
