#include "../../logic/logic.h"
#include "../parser.h"
#include "../../libft/libft.h"

/*
** parser_redir: парсим рудиректы.
*/

void	parser_redir(char **map_comand, t_parser *p, char **line, t_file *file)
{
	(void)line;
	// int fd;

	p->second_arg_redir = ft_strdup(map_comand[0]);
	map_comand[0] = ft_strdup(p->first_arg_redir);
	if (p->flag_redir == 1)
	{
		back_redirect(file, p->second_arg_redir);
		pipe_process(p->map_comand, p, file);
	}
	if (p->flag_redir == 2)
	{
		get_pipe_id(file);
		forward_redirect(file, p->second_arg_redir);
		pipe_process(p->map_comand, p, file);
		// if ((fd = open(p->second_arg_redir, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		// 	error("The file did not open or was not created", 11);
		// write(fd, p->first_arg_redir, ft_strlen(p->first_arg_redir));
		// close(fd);
	}
	if (p->flag_redir == 3)
	{
		get_pipe_id(file);
		double_redirect(file, p->second_arg_redir);
		pipe_process(p->map_comand, p, file);
	}
	// else if (p->flag_redir == 3)
	// {
	// 	printf("I AM HERE\n");
	// 	if ((fd = open(p->second_arg_redir, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
	// 		error("The file did not open or was not created", 11);
	// 	write(fd, p->first_arg_redir, ft_strlen(p->first_arg_redir));
	// 	close(fd);
	// }
	p->flag_redir = 0;
}
