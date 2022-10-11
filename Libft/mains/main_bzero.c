/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:36:37 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/09 08:45:31 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <strings.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	l;

	i = 0;
	while (i < ac)
	{
		l = ft_strlen(av[i]);
		if (l > 3)
		{
			bzero((void *)(*(av + i) + 3), 1);
			printf("%s\n", *(av + i));
			ft_bzero((void *)(*(av + i) + 1), 1);
			printf("%s\n", *(av + i));
		}
		i ++;
	}
	return (0);
}
