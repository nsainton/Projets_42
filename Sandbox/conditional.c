/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:37:23 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/20 11:28:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int	min(int a, int b)
{
	return ((a < b) * a + (b <= a) * b);
}

int	main(void)
{
	int		a;
	int		b;
	float	y;
	float	x;

	a = 1000;
	b = 2213;
	printf("%d\n", min(b, a));
	y = (x = 3, sqrt(x)); //Doesn't comply with the norm
	return (0);
}
