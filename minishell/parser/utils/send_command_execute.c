#include "../../parser/parser.h"
#include "../../logic/logic.h"

/*
** send_command_execute: отправка команд на выполнение.
*/

void send_command_execute(char **map_comand, t_parser *p)
{
	if (map_comand[0] == NULL)
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (!ft_strcmp(map_comand[0], "$?"))
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(ft_itoa(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	else if (!ft_strcmp(map_comand[0], "pwd"))
	{
		print_pwd();
		write(1, "\n", 1);
	}
	else if (!ft_strcmp(map_comand[0], "cd"))
	{
		if (map_comand[1] != NULL && !ft_strcmp(map_comand[1], ".."))
			cd("..");
		else if(map_comand[1] == NULL || !ft_strcmp(map_comand[1], "~"))
			cd("");
		else if(map_comand[1] != NULL)
			cd(map_comand[1]);
	}
	else if (!ft_strcmp(map_comand[0], "export"))
	{
		if (map_comand[1] != NULL)
			export_var(map_comand[1]);
		else
			export();
	}
	else if (!ft_strcmp(map_comand[0], "unset"))
	{
		if (map_comand[1] != NULL)
			unset(map_comand[1]);
	}
	else if (!ft_strcmp(map_comand[0], "env"))
	{
		if (map_comand[1] == NULL)
			print_env();
		else
		{
			ft_putstr_fd(map_comand[0], 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(map_comand[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
	}
	else if (!ft_strcmp(map_comand[0], "exit"))
	{
		if (map_comand[1] == NULL)
		{
			ft_putstr_fd("exit\n", 2);
			exit(0);
		}
		else
		{
			ft_putstr_fd("exit\n", 2);
			exit(ft_atoi(map_comand[1]));
		}
	}
	else if (!ft_strcmp(map_comand[0], "echo"))
	{
		if (map_comand[1] != NULL)
			ft_echo(map_comand[1], p->flag_echo_n, p->coll_space);
		else if (map_comand[1] == NULL)
			ft_putchar('\n');
	}
	else
	{
		if (map_comand[0] != NULL)
		{
			if (!exec(map_comand[0], map_comand))
			{
				write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
				ft_putstr_fd(map_comand[0], 2);
				ft_putstr_fd(": command not found\n", 2);
			}
		}
	}
}
