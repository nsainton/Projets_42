/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:00:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/18 18:28:27 by nsainton         ###   ########.fr       */
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

	if (test == NULL)
		return ;
	fd = open(test, O_RDONLY);
	if(fd > -1)
		printf("File : %s has been oppened\n", test);
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
	printf("File : %s has been closed\n", test);
}

static void	ft_time(char *test)
{
	clock_t	start;
	double	cpu_time;

	start = clock();
	ft_test(test);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("The file has been printed in %f seconds", cpu_time);
}

int	main(void)
{
	ft_time("test.c");
	ft_time("get_next_line.c");
	ft_time("garbage/test");
	ft_time("Bonjour");
	return (0);
}
