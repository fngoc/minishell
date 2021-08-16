#include "../../minishell.h"

void	print_promt(char *str_print)
{
	write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
	ft_putstr_fd(str_print, 2);
}
