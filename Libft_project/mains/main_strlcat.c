/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:38:35 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 17:05:16 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	test[100];
	int		i;
	int		length;

	i = 1;
	*test = 0;
	while(i < ac)
	{
	/*
		length = strlcpy(test, *(av + i));
		printf("Voici la copie réalisée par strlcpy : \"%s\"", test);
		printf(" et le nombre renvoyé : %d\n", length);
	*/
		length = ft_strlcat(test, *(av + i), 10);
		printf("Voici la concaténation réalisée par ft_strlcat : \"%s\"", test);
		printf(" et le nombre renvoyé : %d\n", length);
		i ++;
	}
	return (0);
}
