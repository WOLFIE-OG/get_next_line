/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:26:21 by otodd             #+#    #+#             */
/*   Updated: 2023/12/06 13:29:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	if (!store)
	{
		store = (char *)malloc(1);
		store[0] = '\0';
	}
	if (!store || !buffer)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(store, 0) + ft_strlen(buffer, 0) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (store[++i] != '\0')
		new_str[i] = store[i];
	j = 0;
	while (buffer[j] != '\0')
		new_str[i++] = buffer[j++];
	new_str[i] = '\0';
	free(store);
	return (new_str);
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
