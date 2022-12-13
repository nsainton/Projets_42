/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:04:02 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/13 12:20:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

static void	ft_test(const char *s, unsigned int start, size_t len)
{
	clock_t	beg;
	char	*ns;
	double	cpu_time;

	beg = clock();
	ns = ft_substr(s, start, len);
	cpu_time = (clock() - beg) / CLOCKS_PER_SEC;
	printf("This is the original string : %s -- and this is the maximal length %ld\n\n",\
	s, len);
	if (start < ft_strlen(s))
		printf("This is the starting point as an integer : %d -- and as a character : %c\n",\
	start, *(s + start));
	else
		printf("The is the starting point as an integer : %d -- it is out of bonds\n", start);
	printf("ft_substr returned : %s -- and took %f seconds to compute\n\n\n", ns, cpu_time);
	if (ns)
		free(ns);
}

int	main(void)
{
	char	t[20] = "Bonjour";

	ft_test(t, 3, 10);
	ft_test(t, 3, 1);
	ft_test(t, 10, 2);
	ft_test(t, 0, 1);
	ft_test(t, 2, 0);
	ft_test(t, 0, 0);
	return (0);
}
