# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/03/13 14:30:04 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
NC=\033[0m

CC 			= cc
NAME		= libftgnl.a
CFLAGS 		= -Wall -Wextra -Werror 

SRCS		= ft_get_next_line.c ft_get_next_line_utils.c

OBJS		= $(SRCS:%.c=obj/%.o)
BUILD_DIR	= build

all: $(NAME)

$(NAME): $(OBJS) | $(BUILD_DIR)
	@echo "[$(GREEN)FTGNL$(NC)]     Building standalone lib..."
	@ar -rcs $(NAME) $(OBJS)
	@mv $(NAME) $(BUILD_DIR)/

$(BUILD_DIR):
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "[$(GREEN)FTGNL$(NC)]     Creating build directory..."; \
		mkdir -p $(BUILD_DIR); \
	fi

module: $(OBJS)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)FTGNL$(NC)]     Creating obj directory..."; \
		mkdir -p obj; \
	fi

obj/%.o: src/%.c include/*.h | dir
	@echo "[$(GREEN)FTGNL$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "[$(YELLOW)FTGNL$(NC)]     Cleaning object files..."
	@rm -rf obj

fclean: clean
	@echo "[$(RED)FTGNL$(NC)]     Cleaning build files..."
	@rm -rf $(BUILD_DIR)/


re: fclean all

.PHONY: all clean fclean re