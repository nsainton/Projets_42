/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:00:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/18 18:20:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

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
//		printf("Here is the ligne number %d : %s", i + 1, line);
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

int	main(void)
{
	ft_test("main.c");
	ft_test("get_next_line.c");
	ft_test("test");
	ft_test("Bonjour");
	return (0);
}

/*
void	ft_print_indexes(t_buffer *buff)
{
	if (buff == NULL)
		return ;
	printf("index : %ld, line_index : %ld\n", buff->index, buff->line_index);
	printf("n_read : %ld\n", buff->n_read);
}

int	main(void)
{
	char		line[100] = {0};
	size_t		i = 0;
	int			fd;
	t_buffer	buff = {{0}, 20, 20, 0};

	fd = open("test", O_RDONLY);
	ft_read(&buff, fd);
	while (buff.n_read > 0)
	{
		ft_print_indexes(&buff);
		ft_fill_line(line, &buff);
		i = 0;
		while (i < buff.line_index)
		{
			printf("%c", *(line + i));
			i ++;
		}
		ft_read(&buff, fd);
	}
	close(fd);
	return (0);
}
*/

/*
int	main(void)
{
	int		fd;
	char	*ns;

	fd = open("test", O_RDONLY);
	ns = ft_get_next_line(fd);
	while (ns)
	{
		printf("%s", ns);
		free(ns);
		ns = ft_get_next_line(fd);
	}
	return (0);
}
*/
