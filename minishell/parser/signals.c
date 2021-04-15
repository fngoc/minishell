#include "../minishell.h"

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
		else
			ft_putendl_fd("^C", 1);
	}
}