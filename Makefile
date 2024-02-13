# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/02/06 14:14:11 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
NAME := libftgnl.a
CFLAGS := -Wall -Wextra -Werror 
SRCS := ft_get_next_line.c ft_get_next_line_utils.c

YELLOW := \033[1;33m
RED := \033[1;31m
GREEN := \033[1;32m
NC := \033[0m
OBJS := $(SRCS:%.c=obj/%.o)
BUILD_DIR = build

module: dir $(OBJS)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)FTGNL$(NC)]     Creating obj directory..."; \
		mkdir -p obj; \
	fi

obj/%.o: src/%.c include/*.h
	@echo "[$(GREEN)FTGNL$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "[$(YELLOW)FTGNL$(NC)]     Cleaning object files..."
	@rm -rf $(OBJS)
	@rm -rf obj

fclean: clean
	@echo "[$(RED)FTGNL$(NC)]     Cleaning build files..."
	@rm -rf $(BUILD_DIR)/

all: dir $(OBJS)
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "[$(GREEN)FTGNL$(NC)]     Creating build directory..."; \
		mkdir -p $(BUILD_DIR); \
	fi
	@echo "[$(GREEN)FTGNL$(NC)]     Building standalone lib..."
	@ar -rcs $(NAME) $(OBJS)
	@mv $(NAME) $(BUILD_DIR)/

re: fclean all