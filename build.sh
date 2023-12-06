# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    build.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 14:46:29 by otodd             #+#    #+#              #
#    Updated: 2023/12/06 13:50:21 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ ! -d "bin" ]; then
	mkdir bin
fi
cc get_next_line.c get_next_line.h get_next_line_utils.c test.c -Wall -Wextra -Werror -g -o bin/main.o -D BUFFER_SIZE=215600
cc get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c test.c -Wall -Wextra -Werror -g -o bin/bonus.o -D BUFFER_SIZE=215600