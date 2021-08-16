#include "../../minishell.h"

static	void	zeroing(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char			*ft_strjoin_free_free(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	zeroing(&i, &j);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			p[i] = s1[i];
			++i;
		}
		free(s1);
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		++i;
		++j;
	}
	free(s2);
	p[i] = '\0';
	return (p);
}
