/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:26:53 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 16:34:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*(str + i))
		i ++;
	return (i);
}

#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		printf("Voici la longueur de \"%s\" : %d ", av[i], ft_strlen(av[i]));
		printf("et ce que strlen en dit : %ld\n", strlen(av[i]));
		i ++;
	}
	return (0);
}
