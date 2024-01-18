/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:20:01 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 13:30:38 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_get_next_line(int fd);
char	*ft_g_strjoin(char *store, char *buffer);
size_t	ft_g_strl(const char *s, int type);
char	*ft_g_strchr(char const *s, int c);
char	*ft_g_read_from_buffer(int fd, char *store);
char	*ft_g_read_line(char *store);
char	*ft_g_read_after_newline(char *store);

#endif