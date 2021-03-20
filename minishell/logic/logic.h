#ifndef LOGIC_H

# define LOGIC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "../libft/libft.h"

void			error(char *str);
char			*get_pwd();
void 			print_pwd();
t_list			*env_copy(char **env_original);
int				arr_size(char **arr);
char			*env_var_param(t_list *env, char *param);
char			*env_var_full_param(t_list *env, char *param);
char			*change_value_by_key(char *key, char *value);
t_list			*env_list_pos(t_list *env, char *param);
void 			echo(char *str, int n_flag);
void			cd(char *dir);
void			export();

typedef struct	list
{
	t_list *env;
}				g_list;

g_list			*params;

#endif