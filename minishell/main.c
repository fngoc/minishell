#include "minishell.h"

/*
** main: запуск программы
*/

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	if(!(params = malloc(sizeof(g_list))))
		error("Allocated error", 11);
	params->env = env_copy(env);
	parser();
	return (0);
}
