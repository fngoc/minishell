#include "../../parser/parser.h"

/*
** check_buffer: провека буфера.
*/

char	*check_buffer(t_parser *p)
{
	p->buf[p->len_str] = 0;
	if (!ft_strcmp(p->buf, "\e[A")) //стрелочка вверх
	{
		if (p->step_history >= 0)
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
			get_history_previous(p);
		}
	}
	else if (!ft_strcmp(p->buf, "\e[B")) //стрелочка вниз
	{
		if (p->step_history < p->len_map)
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
			get_history_next(p);
		}
		else if (p->step_history >= p->len_map)
		{
			ft_bzero(p->str, ft_strlen(p->str));
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		}
	}
	else if (!ft_strcmp(p->buf, "\177")) //клавиша backspase
	{
		if (ft_strlen(p->str) != 0)
		{
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", 0), 1, ft_putchar);
			write(1, p->buf, p->len_str);
			++p->backspace;
		}
	}
	else if (!ft_strcmp(p->buf, "\t"))
	{
		ft_bzero(p->str, ft_strlen(p->str));
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		free(p->buf);
		return (NULL);
	}
	else if (!ft_strcmp(p->buf, "\e[C") || !ft_strcmp(p->buf, "\e[D")) //замена клавишь влево и вправо
		return (p->buf);
	else // печать символа
	{
		if (!ft_strcmp(p->buf, "\n"))
		{
			free(p->buf);
			return (NULL);
		}
		else
			write(1, p->buf, p->len_str);
	}
	return (p->buf);
}
