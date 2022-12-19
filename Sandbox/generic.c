/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 08:39:39 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/17 09:01:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define cbrt(x) _Generic((x), int : cbrti, double : cbrtd, long long int : cbrtll, default : cbrtll)(x)

int	cbrti(int x)
{
	printf("INT\n");
	return (0);
}

double cbrtd(double x)
{
	printf("DOUBLE\n");
	return (0);
}

long long int cbrtll(long long int x)
{
	printf("LONG LONG INT\n");
	return (0);
}

int	main(void)
{
	int	i = 3;
	char	*s;
	s = _Generic(1.0, int : "int", double : "double",\
	default : "neither in nor double");
	i ++;
	printf("%s\n", s);
	cbrt(120LL);
	cbrt(120);
	cbrt(120.0);
	cbrt(120.0F);
	return (0);
}
