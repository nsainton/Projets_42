/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lowup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:43:59 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 17:55:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <ctype.h>

static void	ft_printchar(int i)
{
	char chars[4];

	chars[0] = (char)tolower(i);
	chars[1] = (char)toupper(i);
	chars[2] = (char)ft_tolower(i);
	chars[3] = (char)ft_toupper(i);
	if (!ft_isprint(i))
	{
		printf("tolower : %d -- ft_tolower : %d\n", chars[0], chars[2]);
		printf("toupper : %d -- ft_toupper : %d\n", chars[1], chars[3]);
	}
	else
	{
		printf("tolower : %c -- ft_tolower : %c\n", chars[0], chars[2]);
		printf("toupper : %c -- ft_toupper : %c\n", chars[1], chars[3]);
	}
	if (chars[0] != chars[2] || chars[1] != chars[3])
		printf("ERROR!!!!!");
}

int	main(void)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		ft_printchar(i);
		i ++;
	}
	return (0);
}
