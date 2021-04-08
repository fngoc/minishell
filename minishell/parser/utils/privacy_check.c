#include "../parser.h"

/*
** checking_single_quotes: одинарных кавычек.
*/

static void checking_single_quotes(char *line)
{
	int coll;
	int flag_in;
	int open;

	coll = 0;
	flag_in = 0;
	open = 0;
	while (*line != '\0')
	{
		if (flag_in == 1 && *line == '\"')
			flag_in = 0;
		else if (open == 0 && *line == '\"')
			flag_in = 1;
		if (flag_in == 0 && *line == '\'')
		{
			++coll;
			open = 1;
		}
		else if (open == 1 && *line == '\'')
		{
			++coll;
			open = 0;
		}
		++line;
	}
	if (coll == 0)
		return ;
	if (coll % 2 != 0)
		error("Unclosed quotation mark 2");
}

/*
** checking_double_quotes: проверка двойных кавычек.
*/

static void checking_double_quotes(char *line)
{
	int coll;
	int flag_in;
	int open;

	coll = 0;
	flag_in = 0;
	open = 0;
	while (*line != '\0')
	{
		if (flag_in == 1 && *line == '\'')
			flag_in = 0;
		else if (open == 0 && *line == '\'')
			flag_in = 1;
		if (flag_in == 0 && *line == '\"')
		{
			++coll;
			open = 1;
		}
		else if (open == 1 && *line == '\"')
		{
			++coll;
			open = 0;
		}
		++line;
	}
	if (coll == 0)
		return ;
	if (coll % 2 != 0)
		error("Unclosed quotation mark 2");
}

/*
** privacy_check: проверка кавычек в строке.
*/

void	privacy_check(char *line)
{
	checking_single_quotes(line);
	checking_double_quotes(line);
}
