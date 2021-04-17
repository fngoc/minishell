#include "../minishell.h"

/*
** parser_commands: проверка строки на команды и кавычки.
*/

void	parser_commands(char *line, t_parser *p, t_file *file)
{
	char *name;
	int i;

	name = NULL;
	p->previous_char = NULL;
	if (!(p->map_comand = ft_calloc(500, sizeof(char *))))
		error("Allocated error", 11);
	i = -1;
	if (*line == ';')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		error("You can not write at the beginning of the command ;", 258);
	}
	if (*line == '|')
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		error("You can not write at the beginning of the command |", 258);
	}
	while (*line != ';' && *line != '|' && *line != '<'
						&& *line != '>' && *line != '\0')
	{
		if (ft_istab(*line))
		{
			p->previous_char = line;
			++line;
		}
		else
		{
			if (i >= 499)
				error("Exceeded the limit on the \
					number of commands per line", 11);
			if (*line == '\"' || *line == '\'')
				quotation_mark_found(p, &i, &name, &line);
			else
				quotation_mark_not_found(p, &i, &name, &line);
			if (p->map_comand[0] != NULL
				&& !ft_strcmp(p->map_comand[0], "echo"))
			{
				p->flag_echo_n = check_echo_flag_n(&line);
				if (p->flag_echo_n == 0 || p->flag_echo_n == 1)
					parser_echo(p, &line, &i);
				break ;
			}
		}
	}
	if (*line == '|')
	{
		get_pipe_id(file);
		pipe_process(p->map_comand, p, file);
	}
	else if ((*line == '>' || *line == '<' || p->redir_here == 1)
										&& p->flag_redir == 0)
	{
		p->redir_here = 1;
		line = what_is_redir(line, p);
		if (p->flag_folder == 1)
		{
			if ((checking_folder(p->map_comand[0])) == 0)
			{
				ft_putstr_fd(p->map_comand[0], 2);
				ft_putendl_fd(": Is a directory", 2);
				return ;
			}
			if (!p->map_comand[0])
				error("syntax error near unexpected token \'newline\'", 15);
			p->file_name = ft_strdup(p->map_comand[0]);
			if (*line == '<' || *line == '>')
			{
				if (p->flag_redir == 1)
					back_redirect(file, p->file_name);
				else if (p->flag_redir == 2)
				{
					get_pipe_id(file);
					forward_redirect(file, p->file_name);
				}
				else if (p->flag_redir == 3)
				{
					get_pipe_id(file);
					double_redirect(file, p->file_name);
				}
				free(p->file_name);
			}
			else
			{
				if (p->flag_redir == 1)
				{
					back_redirect(file, p->file_name);
					pipe_process(p->map_command_redir, p, file);
				}
				else if (p->flag_redir == 2)
				{
					get_pipe_id(file);
					forward_redirect(file, p->file_name);
					pipe_process(p->map_command_redir, p, file);
				}
				else if (p->flag_redir == 3)
				{
					get_pipe_id(file);
					double_redirect(file, p->file_name);
					pipe_process(p->map_command_redir, p, file);
				}
				free(p->file_name);
				free_map(p->map_command_redir);
			}
			p->flag_folder = 0;
			p->redir_here = 0;
		}
		else
			set_redir_map(p);
	}
	else if (p->flag_folder == 1 && p->redir_here == 0 && p->flag_redir == 0)
	{
		if ((checking_folder(p->map_comand[0])) == 0)
		{
			ft_putstr_fd(p->map_comand[0], 2);
			ft_putendl_fd(": Is a directory", 2);
			return ;
		}
		if (!p->map_comand[0])
			error("syntax error near unexpected token \'newline\'", 15);
		p->file_name = ft_strdup(p->map_comand[0]);
		line = what_is_redir(line, p);
		if (p->flag_redir == 1)
		{
			back_redirect(file, p->file_name);
			pipe_process(p->map_command_redir, p, file);
		}
		else if (p->flag_redir == 2)
		{
			get_pipe_id(file);
			forward_redirect(file, p->file_name);
			pipe_process(p->map_command_redir, p, file);
		}
		else if (p->flag_redir == 3)
		{
			get_pipe_id(file);
			double_redirect(file, p->file_name);
			pipe_process(p->map_command_redir, p, file);
		}
		free(p->file_name);
		free_map(p->map_command_redir);
	}
	else if (p->flag_redir != 0)
	{
		parser_redir(p->map_comand, p, file, *line);
	}
	else
		send_command_execute(p->map_comand, p);
	free_map(p->map_comand);
	if (*line == ';')
	{
		p->flag_folder = 0;
		p->redir_here = 0;
		p->flag_redir = 0;
		p->flag_please = 0;
		p->flag_please_1 = 0;
	}
	if (ft_strlen(line) > 1)
	{
		if (*line == '>')
		{
			if (*(line + 1) == '>')
			{
				++line;
				p->flag_please = 1;
			}
			else
				p->flag_please = 2;
		}
		if (*line == '<')
			p->flag_please_1 = 1;
		parser_commands(++line, p, file);
	}
	p->flag_echo_n = 0;
	p->flag_quotation_mark = 0;
}
