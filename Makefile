# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/02/02 18:06:37 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_get_next_line.c ft_get_next_line_utils.c

YELLOW := \033[1;33m
RED := \033[1;31m
GREEN := \033[1;32m
NC := \033[0m

OBJS := $(SRCS:%.c=obj/%.o)

all: dir $(OBJS)

dir:
	@echo "$(GREEN)[GNL] Creating obj directory...$(NC)"
	mkdir -p obj

obj/%.o: src/%.c
	@echo "$(GREEN)[GNL] Compiling $< --> $@$(NC)"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "$(RED)[GNL] Cleaning object files...$(NC)"
	rm -rf $(OBJS)
	rm -rf obj

re: all
