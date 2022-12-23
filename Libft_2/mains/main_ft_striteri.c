/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:14:07 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/14 17:44:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>

static void	f(unsigned int a, char *s)
{
	if (s == NULL)
		return ;
	*(s + a) = 'n';
}

static void	ft_test(char *s, void (*f) (unsigned int, char *))
{
	clock_t	start;
	double	cpu_time;

	printf("This is the original string : %s\n", s);
	start = clock();
	ft_striteri(s, f);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("This is the modified string : %s\n", s);
	printf("ft_striteri modified the string in %f seconds\n\n\n", cpu_time);
}

int	main(void)
{
	char	c[30] = "Bonjour";

	ft_test(c, f);
	return (0);
}
