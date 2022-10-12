/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/12 17:15:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

static void	ft_comp_func(const char *s1, const char *s2, size_t n)
{
	clock_t	start;
	double	cpu_time_used[2];
	char	*returned_values[2];

	start = clock();
	returned_values[0] = strnstr(s1, s2, n);
	cpu_time_used[0] = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	returned_values[1] = ft_strnstr(s1, s2, n);
	cpu_time_used[1] = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("This is the first string : %s -- And this is the second : %s\n\n",\
	s1, s2);
	printf("strstr returned : %s -- and took %f seconds to execute\n",\
	returned_values[0], cpu_time_used[0]);
	printf("ft_strnstr returned : %s -- and took %f seconds to execute\n",\
	returned_values[1], cpu_time_used[1]);
	printf("The time difference between both functions is %f seconds\n\n\n",\
	cpu_time_used[1] - cpu_time_used[0]);
}

int	main(void)
{
	ft_comp_func("Bonjour", "jour", 10);
	ft_comp_func("Comment ça va ?", "Ajd ?", 5);
	ft_comp_func("Comment", "Commend", 2);
	ft_comp_func("Comment", "Commend", 10);
	ft_comp_func("Comment", "omm", 10);
	ft_comp_func("Comment", "ent", 4);
	ft_comp_func("Comment", "", 10);
}
