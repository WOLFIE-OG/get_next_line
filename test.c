/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:16:11 by otodd             #+#    #+#             */
/*   Updated: 2023/11/28 17:44:33 by otodd            ###   ########.fr       */
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
	char	*c_line;

	i = 0;
	fd = open("big_line_with_nl", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return ;
	}

	printf(BBLU"\n%s\n"reset, EDGES);
	printf("|\n| %s ["BBLU"%d"reset"]\n|\n", "Opening fd with buffer size of", BUFFER_SIZE);

	while ((c_line = get_next_line(fd)) != NULL)
	{
		printf("| ["BBLU"%d"reset"] - ["BGRN"%zu"reset"] - %s", i++, ft_strlen(c_line, 0), c_line);
		free(c_line);
	}

	close(fd);
	printf("\n|"BBLU"\n%s\n"reset, EDGES);
}


int	main(void)
{
	test_single();
	return (0);
}
