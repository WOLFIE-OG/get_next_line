# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/01/19 19:10:15 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_get_next_line.c ft_get_next_line_utils.c

OBJS = $(SRCS:%.c=obj/%.o)

all: dir $(OBJS)

dir:
	mkdir -p obj

obj/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS) 

clean:
	rm -rf $(OBJS)
	rm -rf obj

re: all
