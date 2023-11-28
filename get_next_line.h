/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:20:01 by otodd             #+#    #+#             */
/*   Updated: 2023/11/28 13:39:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *store, char *buffer);
size_t	ft_strlen(const char *s, int type);
char	*ft_strchr(char const *s, int c);
char	*read_from_buffer(int fd, char *store);
char	*read_line(char *store);
char	*read_after_newline(char *store);
char	*free_and_return(char *ptr);

#endif