/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:00:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/13 05:31:15 by nsainton         ###   ########.fr       */
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

	printf("FILE : %s\n", test);
	fd = open(test, O_RDONLY);
	if (! (test && *test))
	{
		fd = 1;
		printf("You may now enter characters : press ^D to finish input\n");
	}
	if (fd > -1 && fd != 1)
	{
		printf("File : %s has been oppened\n", test);
		printf("Its fd is : %d\n", fd);
	}
	else
		printf("FD: %d\n", fd);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		printf("%s", line);
		i ++;
		free(line);
		line = get_next_line(fd);
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
	else if (fd != 1 && fd > -1)
		printf("File : %s has been closed\n", test);
	else
		printf("Thanks for using the get_next_line function\n");
}

static void	ft_time(char *test)
{
	clock_t	start;
	double	cpu_time;

	start = clock();
	ft_test(test);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("The entry has been processed in %f seconds\n", cpu_time);
}

int	main(void)
{
	ft_time("unit_test.c");
	ft_time("test.txt");
	ft_time("Bonjour");
	return (0);
}
