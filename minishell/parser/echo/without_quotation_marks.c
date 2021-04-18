/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_quotation_marks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:23:28 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 16:24:14 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	void	dollar_found(char **str, char **line, char **tmp, t_norm *n)
{
	*tmp = NULL;
	while (**line != ' ' && **line != '\"' && **line != '\'' && **line != '\0')
	{
		if (**line == '\\')
		{
			++(*line);
			n->flag = 1;
			n->buf = ft_strjoin_char_free(n->buf, **line);
			continue ;
		}
		*tmp = ft_strjoin_char_free(*tmp, *(*line)++);
	}
	if ((*tmp = get_var_param(params->env, delet_first(*tmp))))
	{
		if (*str != NULL)
			*str = ft_strjoin_fix(*str, *tmp);
		else
			*str = ft_strdup(*tmp);
	}
	if (n->flag)
		*str = ft_strjoin_fix(*str, n->buf);
}

static	void	double_mark_found(char **str, char **line, char **tmp)
{
	++(*line);
	while (**line != '\"' && **line != '\0')
	{
		if (**line != '$')
			*str = ft_strjoin_char_free(*str, *(*line)++);
		if (**line == '$')
		{
			*tmp = NULL;
			while (**line != ' ' && **line != '\"'
				&& **line != '\'' && **line != '\\')
				*tmp = ft_strjoin_char_free(*tmp, *(*line)++);
			if ((*tmp = get_var_param(params->env, delet_first(*tmp))))
			{
				if (*str != NULL)
					*str = ft_strjoin_fix(*str, *tmp);
				else
					*str = *tmp;
			}
		}
	}
	if (**line == '\"')
		++(*line);
}

static	void	else_step(char **line, char **str)
{
	if (**line == '\\')
		++(*line);
	*str = ft_strjoin_char_free(*str, *(*line)++);
}

static	int		continue_func_norm(char **line, char **str)
{
	++(*line);
	if (**line == '\'')
	{
		++(*line);
		return (1);
	}
	else
		write_cycle(line, str);
	if (**line == '\'')
		++(*line);
	if (**line == '\"')
		return (1);
	return (0);
}

char			*without_quotation_marks(char **line)
{
	char	*str;
	char	*tmp;
	t_norm	n;

	n.flag = 0;
	n.buf = NULL;
	str = NULL;
	while (**line != ' ' && **line != '\0')
	{
		if (**line == '$')
			dollar_found(&str, line, &tmp, &n);
		if (**line == '\"')
			double_mark_found(&str, line, &tmp);
		if (**line == '\'')
		{
			if (continue_func_norm(line, &str) == 1)
				continue ;
		}
		if (ft_strlen(*line) > 0)
			else_step(line, &str);
	}
	return (str);
}
