#ifndef PARSER_H

# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>

# include <fcntl.h> // для open

# include <string.h> // для strcmp, позже удалить

void    parser(void);

void    error(char *str);

int     ft_putchar(int c);

struct  termios init(void);

int     make_file(void);

int     ft_strcmp(const char *str1, const char *str2);

void	set_line(char *str, int fd, char **map, int *len_map);

char    *delet_backspace(char *str, int coll_backspace);

#endif