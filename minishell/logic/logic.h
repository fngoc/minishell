#ifndef LOGIC_H

# define LOGIC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

void	error(char *str);
char	*get_path();
char	**env_copy(char **env_original);
int		arr_size(char **arr);
char	*find_env_var(char **env, char *param);

#endif