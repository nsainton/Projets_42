/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:02:35 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 19:26:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (NULL);
	tab = (int *)malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	i = min;
	while (i < max)
	{
		*(tab + i - min) = i;
		i ++;
	}
	return (tab);
}

#include <stdio.h>

void	ft_print_tab(int *tab, int size);

int	main(int ac, char **av)
{
	int	*tab;
	int	a1;
	int	a2;

	if (ac != 3)
	{
		printf("Invalid number or arguments\n");
		return (1);
	}
	a1 = atoi(av[1]);
	a2 = atoi(av[2]);
	tab = ft_range(a1, a2);
	if (tab == NULL)
	{
		printf("Allocation error\n");
		return (2);
	}
	ft_print_tab(tab, a2 - a1);
	free(tab);
	return (0);
}

void	ft_print_tab(int *tab, int size)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	printf("[");
	while (i < size - 1)
	{
		printf("%d, ", *(tab + i));
		i ++;
	}
	printf("%d]\n", *(tab + i));
}
