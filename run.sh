# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 14:46:37 by otodd             #+#    #+#              #
#    Updated: 2023/11/29 17:15:37 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

./build.sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out multiple_line_with_nl
