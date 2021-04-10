#include "logic/logic.h"
#include "parser/parser.h"
#include "libft/libft.h"

/*
** ft_quit: обработка сигнала ctr+\.
*/

void	ft_quit(int sig)
{
	int		pid;
	int		status;

	(void)sig;
	pid = waitpid(-1, &status, WNOHANG);
	if (!pid)
		ft_putendl_fd("Quit: 3", 1);
}

/*
** ft_sigint: обработка сигнала ctr+с.
*/

void	ft_sigint(int sig)
{
	int		pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		if (pid)
			write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
	}
}

/*
** main: запуск программы
*/

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGQUIT, ft_quit);
	signal(SIGINT, ft_sigint);
	params = malloc(sizeof(g_list));
	params->env = env_copy(env);
	parser();
	return (0);
}
