/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:03:52 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 13:35:22 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	numbers[11];
	int		i;

	i = 0;
	while (i < 10)
	{
		numbers[i] = i + 48;
		i ++;
	}
	numbers[i] = i;
	write(1, numbers, 11);
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}
