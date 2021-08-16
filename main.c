#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	if (!(g_params = malloc(sizeof(t_env))))
		error("Allocated error", 11);
	g_params->env = env_copy(env);
	dup2(STDOUT_FILENO, 3);
	dup2(STDIN_FILENO, 4);
	parser();
	return (0);
}
