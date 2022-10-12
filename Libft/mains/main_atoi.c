/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/12 17:40:55 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>

static void	ft_comp_func(const char *s1)
{
	clock_t	start;
	double	cpu_time_used[2];
	int		returned_values[2];

	start = clock();
	returned_values[0] = atoi(s1);
	cpu_time_used[0] = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	returned_values[1] = ft_atoi(s1);
	cpu_time_used[1] = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("The string passed as an argument is : %s\n", s1);
	printf("atoi returned : %d -- and took %f seconds to execute\n",\
	returned_values[0], cpu_time_used[0]);
	printf("ft_atoi returned : %d -- and took %f seconds to execute\n",\
	returned_values[1], cpu_time_used[1]);
	printf("The time difference between both functions is %f seconds\n\n\n",\
	cpu_time_used[1] - cpu_time_used[0]);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_comp_func(av[i]);
		i ++;
	}
	return (0);
}
