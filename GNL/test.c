/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:00:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/22 17:55:40 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

static void	ft_open_files(int nb, char **tab, int *fd)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		*(fd + i) = open(*(tab + i), O_RDONLY);
		if (*(fd + i) == -1)
			printf("Error while openning file : %s\n", *(tab + i));
		else
		{
			printf("File : %s has been opened\n", *(tab + i));
			printf("And this is it's file descriptor : %d\n", *(fd + i));
		}
		i ++;
	}
}

static void	ft_close_files(int nb, char **tab, int *fd)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		if (*(fd + i) > -1)
		{
			if (close(*(fd + i)) == -1)
				printf("Error while closing file : %s\n", *(tab + i));
			else
				printf("File : %s has been closed\n", *(tab + i));
		}
		i ++;
	}
	printf("All open files have been processed\n");
}

static void	ft_gnl(int *fd, int nb)
{
	int		i;
	int		j;
	char	*line;

	printf("Entering ft_gnl\n");
	i = 1;
	while (i < nb)
	{
		printf("%d\n", *(fd + i));
		line = ft_get_next_line(*(fd + i));
		j = 1;
		while (line != NULL)
		{
			printf("This is the line %d from the file descriptor %d : %s", j, *(fd + i), line);
			j ++;
			free(line);
			line = ft_get_next_line(*(fd + i));
		}
		i ++;
	}
}

static void	ft_test(int nb, char **tab)
{
	int		*fd;

	fd = (int *)malloc(nb * sizeof(int));
	if (fd == NULL)
		return ;
	ft_open_files(nb, tab, fd);
	printf("Files Opened\n");
	ft_gnl(fd, nb);
	ft_close_files(nb, tab, fd);
}

static void	ft_time(int ac, char **av)
{
	clock_t	start;
	double	cpu_time;

	start = clock();
	ft_test(ac, av);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("The entry has been processed in %f seconds\n", cpu_time);
}

int	main(int ac, char **av)
{
	ft_time(ac, av);
	return (0);
}
