/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:44:29 by fuyar             #+#    #+#             */
/*   Updated: 2025/07/15 17:21:56 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!ret)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	free(s1);
	return (ret);
}
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("a.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
}