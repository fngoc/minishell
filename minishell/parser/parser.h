#ifndef PARSER_H

# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <fcntl.h> 

typedef struct s_parser
{
    char	**map;
	int		len_map;
	char	*buf;
	char	*str;
	int		len;
	int		backspace;
    int		step_history;
}               t_parser;



void    parser(void);

void    error(char *str);

int     ft_putchar(int c);

struct  termios init(void);

int     make_file(void);

int     ft_strcmp(const char *str1, const char *str2);

void	set_line(char *str, int fd, t_parser *p);

char    *delet_backspace(char *str, int coll_backspace);

#endif