/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:22:53 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 13:26:03 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n > -1)
		ft_putchar('P');
	else
		ft_putchar('N');
}

#include <stdlib.h>
int	main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_is_negative(atoi(av[i]));
		ft_putchar(10);
		i ++;
	}
	return (0);
}
