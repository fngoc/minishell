#include "logic.h"

//что будет приходить?
void 	echo(char *str, char n_flag) {
	if (n_flag == 'n')
		printf("%s\n", str);
	else
		printf("%s",str);
}

