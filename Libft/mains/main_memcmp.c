/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/12 16:24:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

static void	ft_comp_func(const void *s1, const void *s2, size_t n)
{
	clock_t	start;
	double	cpu_time_used[2];
	int		returned_values[2];

	start = clock();
	returned_values[0] = memcmp(s1, s2, n);
	cpu_time_used[0] = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	returned_values[1] = ft_memcmp(s1, s2, n);
	cpu_time_used[1] = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("This is the first string : %s -- And this is the second : %s\n",\
	(char *)s1, (char *)s2);
	printf("memcmp returned : %d -- and took %f seconds to execute\n",\
	returned_values[0], cpu_time_used[0]);
	printf("ft_memcmp returned : %d -- and took %f seconds to execute\n",\
	returned_values[1], cpu_time_used[1]);
}

int	main(void)
{
	ft_comp_func((void *)"Bonjour", (void *)"Les amis", 4);
	ft_comp_func((void *)"Comment ça va ?", (void *)"Ajd ?", 5);
	ft_comp_func((void *)"Comment", (void *)"Commend", 7);
	ft_comp_func((void *)"Comment", (void *)"Commend", 6);
	ft_comp_func((void *)"Comment", (void *)"Commend", 8);
}
