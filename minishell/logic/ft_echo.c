#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

static char	*ft_strjoin_fix(char *s1, char *s2)
{
	char	*p;

	p = s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	free(p);
	return (s1);
}

static char **pars_line(char *line)
{
	char *str_add;
	char *tmp;
	int i;
	char **map_arg = ft_calloc(500, sizeof(char **));

	i = -1;
	while (*line != '\0')
	{
		if (*line == ' ')
			++line;
		else if (*line == '\'' || *line == '\"')
		{
			if (*line == '\'')
			{
				++line;
				str_add = NULL;
				while (*line != '\'' && *line != '\0')
					str_add = ft_strjoin_char_free(str_add, *line++);
				map_arg[++i] = ft_strdup(str_add);
				free(str_add);
			}
			else if (*line == '\"')
			{
				++line;
				str_add = NULL;
				if (*line != '$')
				{
					while (*line != '\"' && *line != '$' && *line != '\0')
						str_add = ft_strjoin_char_free(str_add, *line++);
				}
				if (*line == '$')
				{
					++line;
					tmp = NULL;
					while (!ft_istab(*line) && *line != '\"' && *line != '\0')
						tmp = ft_strjoin_char_free(tmp, *line++);
					if ((tmp = get_var_param(params->env, tmp)))
					{
						str_add = ft_strjoin_fix(str_add, tmp);
						free(str_add);
					}
				}
				map_arg[++i] = ft_strdup(str_add); //сега
				free(str_add);
			}
		}
		else
		{
			str_add = NULL;
			if (*line != '$')
			{
				while (*line != '\"' && *line != ' ' && *line != '$' && *line != '\0')
					str_add = ft_strjoin_char_free(str_add, *line++);
			}
			if (*line == '$')
			{
				++line;
				tmp = NULL;
				while (!ft_istab(*line) && *line != '\0')
					tmp = ft_strjoin_char_free(tmp, *line++);
				free(str_add);
				if ((tmp = get_var_param(params->env, tmp)))
				{
					tmp = ft_strjoin(str_add, tmp);
					free(str_add);
				}
			}
			map_arg[++i] = ft_strdup(tmp);
			free(str_add);
		}
	}
	return (map_arg);
}

void 	ft_echo(char *line, int n_flag)
{
	// char *str_env;
	char **map_arg;
	// int tap;
	
	map_arg = ft_calloc(500, sizeof(char **));
	map_arg = pars_line(line);
	while (*map_arg != NULL)
	{
		printf("%s\n", *map_arg);
		++map_arg;
	}

	// tap = 0;
	// while (*line != '\0')
	// {
	// 	if (ft_istab(*line))
	// 	{
	// 		if (tap == 0)
	// 		{
	// 			ft_putchar_fd(*line, 1);
	// 			tap = 1;
	// 		}
	// 		++line;
	// 	}
	// 	else if (*line == '\'' || *line == '\"')
	// 	{
			
	// 		if (*line == '\'')
	// 		{
	// 			++line;
	// 			while (*line != '\'' && *line != '\0')
	// 				ft_putchar_fd(*line++, 1);
	// 			ft_putchar_fd(' ', 1);
	// 		}
	// 		else if (*line == '\"')
	// 		{
	// 			++line;
	// 			if (*line != '$')
	// 				ft_putchar_fd(*line, 1);
	// 			else if (*line == '$')
	// 			{
	// 				++line;
	// 				str_env = NULL;
	// 				while (!ft_istab(*line) && *line != '\"'&& *line != '\0')
	// 					str_env = ft_strjoin_char_free(str_env, *line++);
	// 				free(str_env);
	// 				if ((str_env = get_var_param(params->env, str_env)))
	// 					ft_putstr_fd(str_env, 1);
	// 			}
	// 		}
	// 		ft_putchar_fd(' ', 1);
	// 	}
	// 	else
	// 	{
	// 		tap = 0;
	// 		if (*line != '$')
	// 			ft_putchar_fd(*line++, 1);
	// 		else if (*line == '$')
	// 		{
	// 			++line;
	// 			str_env = NULL;
	// 			while (!ft_istab(*line) && *line != '\0')
	// 				str_env = ft_strjoin_char_free(str_env, *line++);
	// 			free(str_env);
	// 			if ((str_env = get_var_param(params->env, str_env)))
	// 				ft_putstr_fd(str_env, 1);
	// 		}
	// 	}
	// }
	
	// (void)flag_quotation_mark;
	// t_list *tmp;
	// char *str_print;
	// int i;
	// int j;

	// tmp = params->env;
	// if (n_flag == 0)
	// 	i = 0;
	// else
	// 	i = 1;
	// while (map[++i] != NULL)
	// {
	// 	if (flag_param == 0)
	// 		ft_putstr_fd(map[i], 1);
	// 	else
	// 	{
	// 		j = 0;
	// 		while (map[i][j] != '\0')
	// 		{
	// 			if (map[i][j] != '$')
	// 				ft_putchar(map[i][j++]);
	// 			else if (map[i][j] == '$')
	// 			{
	// 				++j;
	// 				str_print = NULL;
	// 				while (!ft_istab(map[i][j]) && map[i][j] != '\0')
	// 					str_print = ft_strjoin_char_free(str_print, map[i][j++]);
	// 				free(str_print);
	// 				if ((str_print = get_var_param(tmp, str_print)))
	// 					ft_putstr_fd(str_print, 1);
	// 			}
	// 		}
	// 	}
	// 	ft_putchar(' ');
	// }
	if (n_flag == 0)
		ft_putchar_fd('\n', 1);
}
