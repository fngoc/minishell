#include "../parser.h"

/*
** privacy_check: проверка кавычек в строке.
*/

void	privacy_check(char *line)
{
	int coll_quote;

	coll_quote = 0;
	while (*line != '\0')
	{
		if (*line == '\\')
		{
			++line;
			if (*line == '\'' || *line == '\"')
				++line;
		}
		if (*line == '\'' || *line == '\"')
			++coll_quote;
		++line;	
	}
	if (coll_quote % 2 != 0)
		error("Incorrect number of quotation marks");
}