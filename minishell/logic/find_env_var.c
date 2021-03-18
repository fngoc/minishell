#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//env - переменные окружения, param - то, что нужно найти
char *find_env_var(char **env, char *param)
{
	int i;
	int len;
	int flag;

	len = arr_size(env);
	i = -1;
	flag = 0;
	while (++i < len)
	{
		if(ft_strncmp(env[i], param, ft_strlen(param)) == 0)
		{
			flag = 1;
			break;
		}
	}
	return (flag ? env[i]+ft_strlen(param) + 1 : "");
}
