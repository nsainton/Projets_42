/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:38:35 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 16:15:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	test[100];
	int		i;
	int		length;

	i = 0;
	while(i < ac)
	{
	/*
		length = strlcpy(test, *(av + i));
		printf("Voici la copie réalisée par strlcpy : \"%s\"", test);
		printf(" et le nombre renvoyé : %d\n", length);
	*/
		length = ft_strlcpy(test, *(av + i), 0);
		printf("Voici la copie réalisée par ft_strlcpy : \"%s\"", test);
		printf(" et le nombre renvoyé : %d\n", length);
		i ++;
	}
	return (0);
}
