#include "../parser.h"

/*
** init: инициализация term.
*/

struct	termios	init(void)
{
    struct	termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, "xterm-256color");
    return (term);
}
