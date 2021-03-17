#include "parser.h"
#include "../libft/libft.h"

int size_command(char *line_command)
{
    int i;
    int size;

    size = 0;
    i = ft_strlen(line_command);
    while (i >= 0)
    {
        if (line_command[i] == ' ')
            break;
        ++size;
        --i;
    }
    return (size);
}

/*
** parser: запуск парсера.
*/

void parser(char **map)
{
    (void)map;
    int coll_command;
    char *buf;
    char *line_command;

    coll_command = -1;
    buf = malloc(sizeof(char ) * 1);
    buf[1] = '\0';
    if (!(line_command = (char *)malloc(sizeof(char) * 1)))
        error("Alloc error\n");
    while ((read(0, buf, 1)) != 0)
    {
        if (buf[0] == ' ' || buf[0] == '\n')
        {
            map[++coll_command] = (char *)malloc(sizeof(char) + size_command(line_command));
            if (coll_command != 0)
                map[coll_command] = ft_substr(line_command, size_command(line_command), ft_strlen(line_command));
            else
                map[coll_command] = ft_substr(line_command, 0, ft_strlen(line_command));
            if (buf[0] == '\n')
                break ;
        }
        line_command = ft_strjoin(line_command, buf);
    }
    printf("Вся линия: %s\n", line_command);
    printf("Первая команда: %s\n", map[0]);
    printf("Вторая команда: %s\n", map[1]);
    printf("Третья команда: %s\n", map[2]);
    printf("Четвертая команда: %s\n", map[3]);
    printf("Пятая команда: %s\n", map[4]);
}
