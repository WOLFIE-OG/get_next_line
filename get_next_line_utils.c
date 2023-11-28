/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:26:21 by otodd             #+#    #+#             */
/*   Updated: 2023/11/28 13:39:36 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, int type)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	if (type == 0)
		while (*s++)
			length++;
	else if (type == 1)
		while (*s && *s++ != '\n')
			length++;
	return (length);
}

char	*ft_strjoin(char *store, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_str;
	size_t	total_length;

	if (!store)
	{
		store = (char *)malloc(1 * sizeof(char));
		store[0] = '\0';
	}
	if (!store || !buffer)
		return (NULL);
	total_length = ft_strlen(store, 0) + ft_strlen(buffer, 0) + 1;
	new_str = (char *)malloc(total_length);
	if (!new_str)
		return (free_and_return(store));
	i = -1;
	j = 0;
	while (store[++i] != '\0')
		new_str[i] = store[i];
	while (buffer[j] != '\0')
		new_str[i++] = buffer[j++];
	new_str[total_length - 1] = '\0';
	free(store);
	return (new_str);
}

char	*free_and_return(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*ft_strchr(char const *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
