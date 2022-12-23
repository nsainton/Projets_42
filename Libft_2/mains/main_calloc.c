/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/12 18:07:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>

static void	ft_free_return(void **tab)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (*(tab + i) != NULL)
			free(*(tab + i));
		i ++;
	}
}

static void	ft_comp_func(size_t nmemb, size_t size)
{
	clock_t	start;
	double	cpu_time_used[2];
	void	*returned_values[2];

	start = clock();
	returned_values[0] = calloc(nmemb, size);
	cpu_time_used[0] = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	returned_values[1] = ft_calloc(nmemb, size);
	cpu_time_used[1] = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("The number of elements is : %ld -- and the size is : %ld\n\n",\
	nmemb, size);
	printf("calloc returned : %p -- and took %f seconds to execute\n",\
	returned_values[0], cpu_time_used[0]);
	printf("ft_calloc returned : %p -- and took %f seconds to execute\n",\
	returned_values[1], cpu_time_used[1]);
	printf("The time difference between both functions is %f seconds\n\n\n",\
	cpu_time_used[1] - cpu_time_used[0]);
	ft_free_return(returned_values);
}

int	main(void)
{
	ft_comp_func(2, 3);
	ft_comp_func(3, 4);
	ft_comp_func(0, 1);
	ft_comp_func(1, 0);
	ft_comp_func(0, 0);
	return (0);
}
