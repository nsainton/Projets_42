/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:22:09 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/19 10:32:15 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <time.h>
#include <stdio.h>

static char	test(unsigned int i, char c)
{
	char	d;

	d = (char)i;
	return (c + d);
}

static void	ft_time(const char *s, char (*f)(unsigned int, char))
{
	clock_t	start;
	double	cpu_time;
	char	*ns;

	start = clock();
	ns = ft_strmapi(s, f);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("This is the base string : %s\nThis is the returned string : %s\n",\
	s, ns);
	printf("ft_strmapi did it's work in %f seconds\n\n\n", cpu_time);
	if (ns != NULL)
		free(ns);
}

int	main(void)
{
	ft_time("Bonjour", test);
	ft_time("Salut", test);
	ft_time("", test);
	ft_time(NULL, test);
	return (0);
}
