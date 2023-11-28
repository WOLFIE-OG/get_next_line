/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:16:11 by otodd             #+#    #+#             */
/*   Updated: 2023/11/28 13:24:39 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ANSI-color-codes.h"
#include <stdio.h>
#include <ctype.h>

char	EDGES[] = "========================================================================================================================================";


void	test_single()
{
	int		fd;
	int		i;
	char	*c_line = "";

	i = 0;
	fd = open("nl", O_RDONLY);
	printf(BBLU"\n%s\n"reset, EDGES);
	printf("|\n| %s ["BBLU"%d"reset"]\n|\n", "Opening fd with buffer size of", BUFFER_SIZE);
	while (c_line != NULL)
	{
		c_line = get_next_line(fd);
		printf("| ["BBLU"%d"reset"] - ["BGRN"%zu"reset"] - %s", i++, sizeof(c_line), c_line);
	}
	printf("\n|"BBLU"\n%s\n"reset, EDGES);
}

int	main(void)
{
	test_single();
	return (0);
}
