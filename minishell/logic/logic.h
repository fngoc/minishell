#ifndef LOGIC_H

# define LOGIC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include <string.h>

void			error(char *str);
char			*get_pwd();
void 			print_pwd();
t_list			*env_copy(char **env_original);
int				arr_size(char **arr);
char			*get_var_param(t_list *env, char *param);
char			*get_var_full_param(t_list *env, char *param);
char			*change_value_by_key(char *key, char *value);
t_list			*get_env_list_pos(t_list *env, char *param);
void 			ft_echo(char **map, int n_flag, int flag_param, int flag_quotation_mark);
void			cd(char *dir);
void			export();
void			sort_export(t_list *new);
void			free_lst_map(t_list **lst);
t_list			*list_copy();
void			export_var(char *var);
void			print_env();
char			*get_key_by_full_param(char *full_param);
int				unset(char *param);
int				exec(char *command, char **argv);
char			*remove_double_quotes(const char *var);
char			**list_to_arr();
void			dollar_variable(char *param);
void			dollar_variable(char *param);
void			errno_exit();
int				is_path_command(char **path, char *command);

		typedef struct	list
{
	t_list *env;
}				g_list;

g_list			*params;

#endif