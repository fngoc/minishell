#include "logic/logic.h"
#include "parser/parser.h"
#include "libft/libft.h"

/*
** main: запуск программы
*/

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	if(!(params = malloc(sizeof(g_list))))
		error("Allocated error", 11);
	params->env = env_copy(env);
	parser();
	return (0);
}
