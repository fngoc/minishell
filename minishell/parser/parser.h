#ifndef PARSER_H

# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>

# include <string.h> // для strcmp, позже удалить

void    parser(void);

void    error(char *str);

int     ft_putchar(int c);

#endif