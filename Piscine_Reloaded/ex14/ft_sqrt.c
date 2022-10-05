/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:40:37 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 16:15:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	root;

	if (nb < 1)
		return (0);
	root = 1;
	while (root <= nb / root)
	{
		if (root * root == nb)
			return (root);
		root ++;
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	temp;

	i = 1;
	while (i < ac)
	{
		temp = atoi(av[i]);
		printf("Voici la racine carrée de %d : %d\n", temp, ft_sqrt(temp));
		i ++;
	}
	return (0);
}
