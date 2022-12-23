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
#include <string.h>

static void	ft_free_return(char **tab)
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

static void	ft_comp_func(const char *s)
{
	clock_t	start;
	double	cpu_time_used[2];
	char	*returned_values[2];

	start = clock();
	returned_values[0] = strdup(s);
	cpu_time_used[0] = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	returned_values[1] = ft_strdup(s);
	cpu_time_used[1] = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("The base string is : %s\n\n", s);
	printf("strdup returned : %s -- and took %f seconds to execute\n",\
	returned_values[0], cpu_time_used[0]);
	printf("ft_strdup returned : %s -- and took %f seconds to execute\n",\
	returned_values[1], cpu_time_used[1]);
	printf("The time difference between both functions is %f seconds\n\n\n",\
	cpu_time_used[1] - cpu_time_used[0]);
	ft_free_return((char **)returned_values);
}

int	main(void)
{
	char	s[100];

	ft_comp_func("Bonjour");
	ft_comp_func("Comment ça va ?");
	ft_comp_func("");
	ft_comp_func(s);
	return (0);
}
