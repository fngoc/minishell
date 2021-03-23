#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//возвращаем только содержимое переменной
//env - наша копия листа, param - параметр, который мы ищем

char *get_var_param(t_list *env, char *param)
{
	int flag;
//	t_list *tmp;
//	char *str;
//
//	tmp = params->env;
	flag = 0;
	while (env)
	{
		if((ft_strncmp(env->content, param, ft_strlen(param)) == 0)
		&& ((int)(env->content[ft_strlen(param)])) == '=')
		{
			flag = 1;
			break;
		}
		env = env->next;
	}
	if (flag)
	{
		return (env->content + ft_strlen(param) + 1);
	}
	return (NULL);
}

//возвращаем всю строку с переменной
char *get_var_full_param(t_list *env, char *param)
{
	int flag;

	flag = 0;
	while (env)
	{
		if(ft_strncmp(env->content, param, ft_strlen(param)) == 0
		   && ((int)(env->content[ft_strlen(param)])) == '=')
		{
			flag = 1;
			break;
		}
		env = env->next;
	}
	if (flag)
		return (env->content);
	return ("");
}

char *change_value_by_key(char *key, char *value)
{
	char *str;
	char *str_tmp;

	str_tmp = ft_strjoin(key,"=");
	str = ft_strjoin(str_tmp, value);
	free(str_tmp);
	return (str);
}

t_list *get_env_list_pos(t_list *env, char *param)
{
	int flag;
	flag = 0;

	while (env)
	{
		if(ft_strncmp(env->content, param, ft_strlen(param)) == 0
		   && ((int)(env->content[ft_strlen(param)])) == '=')
		{
			flag = 1;
			break;
		}
		env = env->next;
	}
	if (flag == 1)
		return (env);
	return (NULL);
}
