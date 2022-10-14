/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:58:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/14 15:35:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>

static void	ft_test(int n)
{
	clock_t	start;
	double	cpu_time;
	char	*ns;

	start = clock();
	ns = ft_itoa(n);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("Here is the integer tested : %d\n", n);
	printf("Here is the string returned by ft_itoa : %s\n", ns);
	printf("The function took %f seconds to run\n\n\n", cpu_time);
	if (ns != NULL)
		free(ns);
}

int	main(void)
{
	ft_test(-2147483648);
	ft_test(2147483647);
	ft_test(-12);
	ft_test(-8);
	ft_test(0);
	ft_test(5);
	ft_test(18);
	return (0);
}
