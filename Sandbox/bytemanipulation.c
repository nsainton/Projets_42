/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytemanipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:45:08 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/31 06:16:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_bytes_integer(int var)
{
	size_t	i;

	i = 0;
	while (i < 32)
	{
		if (var & 1 << (31 - i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i ++;
	}
	write(1, "\n", 1);
}

void	print_byte(char c)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << (7 - i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i ++;
	}
}

void	print_bytes_individual(int var)
{
	size_t	size;
	size_t	i;
	int		tmp;

	size = sizeof var;
	i = size - 1;
	while (i)
	{
		print_byte(*((char *)&tmp + i));
		i --;
	}
	print_byte(*(char *)&tmp);
	write(1, "\n", 1);
}

int	main(void)
{
	int	x;

	x = 1;
	print_bytes_integer(x);
	print_bytes_individual(x);
	printf("%d\n", x);
	*((char *)&x + 1) = -1;
	printf("%d\n", x);
	print_bytes_integer(x);
	print_bytes_individual(x);
	return (0);
}
