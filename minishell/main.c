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

	write(1, "Welcome to Minishell Fngoc and Drarlean!\n", 41);

	params = malloc(sizeof (g_list));
	params->env = env_copy(env);
	
	parser();


//	printf("%s\n", env_var_full_param(params->env, "PWD"));
//	cd("");
//	printf("%s\n", env_var_full_param(params->env, "PWD"));

	return (0);
}
