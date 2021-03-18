#include "logic.h"

//str - аргумент, который надо напечатать, n flag - перевод строки
void 	echo(char *str, int n_flag)
{
	if (n_flag == 1)
		printf("%s\n", str);
	else
		printf("%s",str);
}

