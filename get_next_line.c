/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:44:23 by fuyar             #+#    #+#             */
/*   Updated: 2024/11/08 16:53:28 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *buf, int fd)
{
	char	*buffer;
	int		reads;

	reads = 1;
	if (!buf)
	{
		buf = malloc(sizeof(char) * 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(buf), NULL);
	while (!ft_strchr_gnl(buf, '\n') && reads != 0)
	{
		reads = read(fd, buffer, BUFFER_SIZE);
		if (reads == -1)
			return (free(buf), free(buffer), NULL);
		buffer[reads] = '\0';
		buf = ft_strjoin_gnl(buf, buffer);
		if (!buf)
			return (free(buffer), NULL);
	}
	return (free(buffer), buf);
}

char	*ft_get_line(char *dst)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!dst[i])
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (dst[++i] && dst[i] != '\n')
		ret[i] = dst[i];
	if (dst[i] == '\n')
	{
		ret[i] = dst[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_get_left_line(char *dst)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst[i])
		return (free(dst), NULL);
	if (dst[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (ft_strlen_gnl(dst) - i + 1));
	if (!ret)
		return (free(dst), NULL);
	j = 0;
	while (dst[i])
		ret[j++] = dst[i++];
	ret[j] = '\0';
	free(dst);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = ft_read_line(buf, fd);
	if (!buf)
		return (NULL);
	ret = ft_get_line(buf);
	if (!ret)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	buf = ft_get_left_line(buf);
	return (ret);
}
