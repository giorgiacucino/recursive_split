#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ft_rec_split(char ***ret, char *in, int words, int lenght)
{
	char **tmp;

	tmp = *ret;
	if (*in == '\0')
	{
		tmp = malloc (sizeof(char *) * (words + 1 + (lenght != 0)));
		tmp[words + (lenght != 0)] = NULL;
		if (lenght != 0)
		{
			tmp[words] = malloc (sizeof(char) * (lenght + 1));
			tmp[words][lenght] = '\0';
		}
	}
	else
	{
		if (*in == ' ' && lenght != 0)
			ft_rec_split(ret, in + 1, words + 1, 0);
		else if (*in == ' ')
			ft_rec_split(ret, in + 1, words, 0);
		else
			ft_rec_split(ret, in + 1, words, lenght + 1);
		tmp = *ret;
		if (*in != ' ')
			tmp[words][lenght] = *in;
		if (*in == ' ' && lenght != 0)
		{
			tmp[words] = malloc (sizeof(char) * (lenght + 1));
			tmp[words][lenght] = '\0';
    	}
	}
	*ret = tmp;
}

char **ft_split(char *s)
{
	char **ret;
	ft_rec_split(&ret, s, 0, 0);
	return (ret);
}