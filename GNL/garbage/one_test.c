/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:00:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/22 17:39:13 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

static void	ft_test(char *test)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(test, O_RDONLY);
	if (! (test && *test))
	{
		fd = 1;
		printf("You may now enter characters : press ^D to finish input\n");
	}
/*
	if (fd > -1 && fd != 1)
		printf("File : %s has been oppened\n", test);
*/
	line = ft_get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		printf("%s", line);
		i ++;
		line = ft_get_next_line(fd);
	}
	if (fd > -1)
		fd = close(fd);
	if (! i)
	{
		printf("Oppening error\n");
		return ;
	}
	if (fd == -1)
		printf("Closing error\n");
/*
	else if (fd != 1 && fd > -1)
		printf("File : %s has been closed\n", test);
	else
		printf("Thanks for using the get_next_line function\n");
*/
}

static void	ft_time(char *test)
{
	clock_t	start;
	double	cpu_time;

	start = clock();
	ft_test(test);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	cpu_time = cpu_time + 1;
//	printf("The entry has been processed in %f seconds\n", cpu_time);
}

int	main(void)
{
	ft_time("gnl_utils.c");
	return (0);
}
