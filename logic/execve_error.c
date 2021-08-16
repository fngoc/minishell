#include "../minishell.h"

static int			err_with_char(char err_name,
		char *command, char *error_text)
{
	if (err_name == 'd')
	{
		print_promt(command);
		ft_putstr_fd(error_text, 2);
		set_errno(126);
		return (1);
	}
	else if (err_name == 'p')
	{
		print_promt(command);
		ft_putstr_fd(error_text, 2);
		set_errno(126);
		return (1);
	}
	else if (err_name == 'f')
	{
		print_promt(command);
		ft_putstr_fd(error_text, 2);
		set_errno(1);
		return (1);
	}
	return (0);
}

static	char		*delet_first_exe(char *str)
{
	char *new_char;

	new_char = ++str;
	return (new_char);
}

static void			command_not_found(char *command)
{
	print_promt(command);
	ft_putstr_fd(": command not found\n", 2);
	set_errno(127);
}

int					err_exit(int err,
		char *command, char err_name, char *err_text)
{
	char *str_print;

	if (*command == '$')
	{
		if ((str_print = get_var_param(g_params->env,
							delet_first_exe(command))))
			command_not_found(str_print);
	}
	else if ((str_print = get_var_param(g_params->env,
							delet_first_exe(command))))
		command_not_found(str_print);
	else if (err_with_char(err_name, command, err_text) == 1)
		return (err);
	else
	{
		print_promt(command);
		ft_putstr_fd(": command not found\n", 2);
		set_errno(127);
	}
	return (err);
}
