#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i;
	
	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char *ft_strchr(char *s1, char c)
{
	size_t i;
	size_t len;

	len = ft_strlen(s1);
	i = 0;
	if (!s1)
		return (NULL);
	while (i < len)
	{
		if (s1[i] == c)
			return (s1 + i);
		i++;
	}
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *ret;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	free(s1);
	return (ret);
}