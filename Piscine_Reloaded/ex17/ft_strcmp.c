/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:40:05 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 17:28:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	stop;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	stop = 1;
	while (*(s1 + i) && *(s2 + i) && stop)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			stop = 0;
			i --;
		}
		i ++;
	}
	return ((unsigned char)*(s1 + i) - \
	(unsigned char)*(s2 + i));
}

#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		printf("Comparaison de %s et %s renvoie : %d ", av[i], av[i + 1], \
		ft_strcmp(av[i], av[i + 1]));
		printf(" et strcmp renvoie : %d\n", strcmp(av[i], av[i + 1]));
		i ++;
	}
	return (0);
}
