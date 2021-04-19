#include "../../minishell.h"

static void		free_strs_execve(char **tmp_join, char **tmp_str)
{
	free(*tmp_join);
	free(*tmp_str);
}

int				execve_path(char *path_non_splitted,
		char **argv, char **ev, char *command)
{
	char	**splitted;
	char	**tmp;
	char	*tmp_str;
	char	*tmp_join;
	int		fd;

	splitted = ft_split(path_non_splitted, ':');
	tmp = splitted;
	while (*splitted)
	{
		tmp_join = ft_strjoin("/", command);
		tmp_str = ft_strjoin(*splitted, tmp_join);
		fd = open(tmp_str, O_RDONLY);
		if (fd > 0)
		{
			exec_command(tmp_str, argv, ev);
			free_strs_execve(&tmp_join, &tmp_str);
			break ;
		}
		close(fd);
		free_strs_execve(&tmp_join, &tmp_str);
		splitted++;
	}
	free_map(tmp);
	return (fd);
}
