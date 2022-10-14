/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:52:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/14 20:58:57 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#define FD fd
static void	ft_test(char c, char *s, int n, int fd)
{
	clock_t	start;
	double	cpu_time;

	start = clock();
	ft_putchar_fd(c, fd);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	ft_putchar_fd(10, fd);
	printf("This is the character : %c -- and ft_putchar took %f seconds\
	to print it to the file descriptor\n", c, cpu_time);
	start = clock();
	ft_putstr_fd(s, fd);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	ft_putchar_fd(10, fd);
	printf("This is the string : %s -- and ft_putstr took %f seconds to print\
	it to the file descriptor\n", s, cpu_time);
	start = clock();
	ft_putendl_fd(s, fd);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	ft_putchar_fd(10, fd);
	printf("This is the string : %s -- and ft_putendl took %f seconds to print\
	it to the file descriptor\n", s, cpu_time);
	start = clock();
	ft_putnbr_fd(n, fd);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	ft_putchar_fd(10, fd);
	printf("This is the number : %d -- and ft_putnbr took %f seconds to print\
	it to the file descriptor\n\n", n, cpu_time);
}

int	main(void)
{
	int	fd;

	fd = open("test", O_CREAT | O_WRONLY);
	if (fd < 0)
		return (1);
	ft_test('c', "Bonjoru", 12, FD);
	ft_test('c', "Bonjour", -2147483648, FD);
	ft_test('a', "SALUT", -2143, FD);
	ft_test('h', NULL, -4, FD);
	ft_test('j', "HEU", 0, FD);
	ft_test('h', "HOIH", 2, FD);
	ft_test('k', "HOIH", 2147483647, FD);
	close(fd);
	return (0);
}
