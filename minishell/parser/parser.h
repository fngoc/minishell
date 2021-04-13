#ifndef PARSER_H

# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include "../libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>

typedef struct	s_file
{
	int		fd_stdin;
	int		fd_stdout;
}				t_file;

typedef struct	list
{
	t_list	*env;
}				g_list;

typedef	struct	s_parser
{
	char		**map_history;
	char		**map_comand;
	int			len_map;
	char		*buf;
	char		*str;
	int			len_str;
	int			backspace;
	int			step_history;
	int			flag_echo_n;
	int			flag_quotation_mark;
	int			coll_space;
	int			flag_redir;
	char		*first_arg_redir;
	char		*second_arg_redir;
}				t_parser;

void			parser(void);

void			error(char *str, int err);

int				ft_putchar(int c);

struct termios	init(void);

int				make_file(void);

int				ft_strcmp(const char *str1, const char *str2);

void			set_line(char const *str, int fd, t_parser *p);

int				is_arrow(char const *buf);

int				ft_istab(char c);

void			free_map(char **map);

char			*delet_last_char(char *str, int coll_backspace);

char			*ft_strjoin_char_free(char *s1, char c);

void			get_history_next(t_parser *p);

void			get_history_previous(t_parser *p);

char			*check_buffer(t_parser *p);

void			send_command_execute(char **map_comand, t_parser *p);

void			parser_commands(char *line, t_parser *p, t_file *file);

void			privacy_check(char *line, t_parser *p);

void			checking_single_quotes(char *line);

void			checking_double_quotes(char *line);

void			ft_sigint(int sig);

void			ft_quit(int sig);

void 			ft_echo(char *str, int n_flag, int memory);

void			send_exit(char **map);

void			send_exec(char **map);

void			send_echo(char **map, t_parser *p);

void			send_env(char **map);

void			send_question_mark(void);

char			*ft_strjoin_free_free(char *s1, char *s2);

char			*delet_first(char *str);

char			*ft_strjoin_fix(char *s1, char *s2);

char			*double_quote(char **line);

char			*single_quote(char **line);

char			*without_quotation_marks(char **line);

void			parser_redir(char **map_comand, t_parser *p, char **line, t_file *file);
char			*get_pwd();
void 			print_pwd();
t_list			*env_copy(char **env_original);
int				arr_size(char **arr);
char			*get_var_param(t_list *env, char *param);
char			*get_var_full_param(t_list *env, char *param);
char			*change_value_by_key(char *key, char *value);
t_list			*get_env_list_pos(t_list *env, char *param);
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
int				is_path_command(char **path, char *command);
void			pipe_process(char **argv, t_parser *p, t_file *file);
void			print_promt(char *str_print);
void			set_errno(int err);
void			redirect(char *file_name);
void 	get_pipe_id(t_file *file);
void 	forward_redirect(t_file *file, char *file_name);

g_list			*params;

#endif
