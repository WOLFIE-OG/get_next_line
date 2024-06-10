/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:50 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 16:53:44 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char	*store[1024];
	char		*c_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = ft_g_read_from_buffer(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	c_line = ft_g_read_line(store[fd]);
	store[fd] = ft_g_read_after_newline(store[fd]);
	return (c_line);
}

char	*ft_g_read_from_buffer(int fd, char *store)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_g_strchr(store, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(store);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		store = ft_g_strjoin(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*ft_g_read_line(char *store)
{
	char	*line;
	int		i;

	i = 0;
	if (!store[i])
		return (NULL);
	line = (char *)malloc(ft_g_strl(store, 1) + 2);
	if (!line)
		return (NULL);
	while (store[i] && store[i] != '\n')
	{
		line[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_g_read_after_newline(char *store)
{
	char	*line;
	int		i;
	int		j;

	i = ft_g_strl(store, 1);
	j = 0;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_g_strl(&store[i + 1], 0) + 1));
	if (!line)
		return (NULL);
	i++;
	while (store[i])
		line[j++] = store[i++];
	line[j] = '\0';
	free(store);
	return (line);
}
