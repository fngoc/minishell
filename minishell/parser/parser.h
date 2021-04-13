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

void			parser_commands(char *line, t_parser *p);

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

void			parser_redir(char **map_comand, t_parser *p, char **line);

#endif
