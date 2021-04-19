#include "../minishell.h"

static	void	set_in_map(int *i, char *name, t_parser *p)
{
	if (ft_strlen(name) > 0)
	{
		p->map_comand[++*i] = ft_strdup(name);
		free(name);
	}
	else
		p->map_comand[++*i] = NULL;
}

void			quotation_mark_not_found(t_parser *p, int *i,
									char **name, char **line)
{
	if (p->previous_char != NULL && *p->previous_char == ' ')
		*name = NULL;
	while (!ft_istab(**line) && **line != ';' && **line != '|'
			&& **line != '>' && **line != '<' && **line != '\0')
	{
		if (**line == '\"' || **line == '\'')
			break ;
		if (**line == '\\')
		{
			++(*line);
			*name = ft_strjoin_char_free(*name, **line);
			++(*line);
			continue ;
		}
		*name = ft_strjoin_char_free(*name, **line);
		++(*line);
	}
	if (**line != '\"' && **line != '\'')
		set_in_map(i, *name, p);
	p->previous_char = NULL;
}
