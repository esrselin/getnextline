/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:02:40 by esakgul           #+#    #+#             */
/*   Updated: 2025/07/17 20:14:45 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *line)
{
	char	*buffer;
	char	*new_line;
	ssize_t	size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(line, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (free(buffer), NULL);
		buffer[size] = '\0';
		new_line = ft_strjoin(line, buffer);
		if (!new_line)
			return (free(buffer), NULL);
		free(line);
		line = new_line;
	}
	free(buffer);
	return (line);
}

static char	*set_line(char *line)
{
	char	*tmp_line;
	size_t	i;
	size_t	j;

	if (!line || line[0] == '\0')
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	tmp_line = malloc(sizeof(char) * (i + 1));
	if (!tmp_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp_line[j] = line[j];
		j++;
	}
	tmp_line[j] = '\0';
	return (tmp_line);
}

static char	*clean_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*cl_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	i++;
	cl_line = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!cl_line)
	{
		free(line);
		return (NULL);
	}
	j = 0;
	while (line[i])
		cl_line[j++] = line[i++];
	cl_line[j] = '\0';
	free(line);
	return (cl_line);
}

char	*get_next_line(int fd)
{
	static char	*line[4096];
	char		*tmp_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = read_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	tmp_line = set_line(line[fd]);
	line[fd] = clean_line(line[fd]);
	return (tmp_line);
}
