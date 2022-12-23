/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:50:31 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/08 15:58:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		printf("Longueur de la chaîne \"%s\" : %ld", av[i], ft_strlen(av[i]));
		printf(" et ce qu\'en dit strlen : %ld\n", strlen(av[i]));
		i ++;
	}
	return (0);
}
