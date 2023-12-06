/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:16:11 by otodd             #+#    #+#             */
/*   Updated: 2023/12/06 14:19:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ANSI-color-codes.h"
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

char	EDGES[] = "========================================================================================================================================";


void	test_single(int	arg_n, char **arg_a)
{
	int		fd;
	int		i;
	char	*c_line;

	(void)arg_n;
	i = 0;
	fd = open(arg_a[1], O_RDONLY);
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


int	main(int arg_n, char **arg_a)
{
	test_single(arg_n, arg_a);
	return (0);
}
