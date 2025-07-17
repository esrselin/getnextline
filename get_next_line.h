/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:46:29 by fuyar             #+#    #+#             */
/*   Updated: 2024/11/08 16:48:05 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10
# endif

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *str, char c);
size_t	ft_strlen_gnl(char *str);
char	*ft_get_left_line(char *dst);
char	*ft_get_line(char *dst);
char	*ft_read_line(char *buf, int fd);
char	*get_next_line(int fd);

#endif