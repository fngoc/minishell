#include "parser.h"
#include "../libft/libft.h"
#include "../logic/logic.h"

/*
** send_command_execute: отправка команд на выполнение.
*/

void send_command_execute(char **map_comand)
{
	if (!ft_strcmp(map_comand[0], "$?"))
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(ft_itoa(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	else if (!ft_strcmp(map_comand[0], "pwd"))
	{
		print_pwd();
		write(1, "\n", 1);
	}
	else if (!ft_strcmp(map_comand[0], "cd"))
	{
		if (map_comand[1] != NULL && !ft_strcmp(map_comand[1], ".."))
			cd("..");
		else if(map_comand[1] == NULL || !ft_strcmp(map_comand[1], "~"))
			cd("");
		else if(map_comand[1] != NULL)
			cd(map_comand[1]);
	}
	else if (!ft_strcmp(map_comand[0], "export"))
		if (map_comand[1] != NULL)
			export_var(map_comand[1]);
		else
			export();
	else if (!ft_strcmp(map_comand[0], "unset"))
	{
		if (map_comand[1] != NULL)
			unset(map_comand[1]);
	}
	else if (!ft_strcmp(map_comand[0], "env"))
	{
		if (map_comand[1] == NULL)
			print_env();
		else
		{
			ft_putstr_fd(map_comand[0], 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(map_comand[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
	}
	else if (!ft_strcmp(map_comand[0], "exit"))
	{
		if (map_comand[1] == NULL)
		{
			ft_putstr_fd("exit\n", 2);
			exit(0);
		}
		else
		{
			ft_putstr_fd("exit\n", 2);
			exit(ft_atoi(map_comand[1]));
		}
	}
	else
	{
		write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		ft_putstr_fd(map_comand[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

/*
** check_command: проверка строки на команды.
*/

void	check_command(char *line, t_parser *p)
{
	char *name;
	int i;

	p->map_comand = ft_calloc(500, sizeof(char *));
	i = -1;
	while (*line != ';' && *line != '\0')
	{
		if (ft_istab(*line))
			++line;
		else
		{
			name = NULL;
			while (!ft_istab(*line) && *line != '\0')
			{
				name = ft_strjoin_char_free(name, *line);
				++line;
			}
			p->map_comand[++i] = ft_strdup(name);
			free(name);
		}
	}
	send_command_execute(p->map_comand);
	free_map(p->map_comand);
	if (ft_strlen(line) > 1)
		check_command(++line, p);

	/* Проверка */
	// int u;
	// u = 0;
	// while (u <= i)
	// 	printf("%s\n", p->map_comand[u++]);
	// free_map(p->map_comand);
}

/*
** check_bufer: провека буфера.
*/

char	*check_bufer(t_parser *p)
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

/*
** read_line: чтение линии.
*/

static	void	read_line(int fd, t_parser *p)
{
	while (p->buf == NULL || ft_strcmp(p->buf, "\4"))
	{
		if (p->buf != NULL)
			free(p->buf);
		p->buf = ft_calloc(2, sizeof(char));
		tputs(save_cursor, 1, &ft_putchar);
		write(1, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
		while (((p->len_str = read(0, p->buf, 100)) != -1) &&
		ft_strcmp(p->buf, "\n") && ft_strcmp(p->buf, "\4"))
		{
			p->backspace = 0;
			p->buf = check_bufer(p);
			if (p->buf == NULL)
				break ;
			if (!is_arrow(p->buf))
			{
				char * tmp_p_str;
				tmp_p_str = ft_strjoin(p->str, p->buf);
				free(p->str);
				p->str = tmp_p_str;
			}
			if (p->backspace)
				p->str = delet_last_char(p->str, 1);
		}
		write(1, "\n", 1);
		p->step_history = p->len_map;
		set_line(p->str, fd, p);
		if (ft_strlen(p->str) > 0)
			check_command(p->str, p);
		ft_bzero(p->str, ft_strlen(p->str));
	}
	free(p->buf);
	free(p->str);
	free_map(p->map_history);
}

/*
** init_parser: начальные значения структуры парсера.
*/

static	void	init_parser(t_parser *p)
{
	p->step_history = -1;
	p->len_map = -1;
	p->flag_step_history_next = 0;
	p->flag_step_history_previou = 0;
	p->map_history = ft_calloc(500, sizeof(char *));
	p->str = ft_calloc(2, sizeof(char));
	p->buf = NULL;
}

/*
** parser: запуск парсера.
*/

void	parser(void)
{
	int				fd;
	t_parser		p;
	struct	termios	term;

	term = init();
	fd = make_file();
	init_parser(&p);
	read_line(fd, &p);
	term.c_lflag |= ~(ECHO);
	term.c_lflag |= ~(ICANON);
}
