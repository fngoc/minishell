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

	write(1, "Welcome to Minishell Fngoc and Drarlean!\n", 41);
//	parser();

	params = malloc(sizeof (g_list));
	params->env = env_copy(env);

	export();

    return 0;
}
