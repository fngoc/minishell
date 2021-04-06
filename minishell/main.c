
#include "logic/logic.h"
#include "parser/parser.h"
#include "libft/libft.h"


/*
** main: запуск программы
*/

int main(int argc, char **argv, char **env) {
	(void) argc;
	(void) argv;
	(void) env;

	params = malloc(sizeof(g_list));
	params->env = env_copy(env);



//	execve("/bin/ls", argv, env);
//	wait(&pid);

	parser();
	// exec("ls", argv);
//	int fd = open("./ls", O_RDONLY);
//	printf("%d\n", fd);

}

