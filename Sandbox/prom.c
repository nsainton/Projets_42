/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:53:53 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/16 16:14:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <complex.h>

int	main(void)
{
	int				i = 7;
	float			x = 0.5;
	float _Complex	z = -1.7 + 2.0 * I;
	int unsigned	n = 0;
	long			l_var = 123456789L;
	float			f_var = l_var;

	i = x;
	printf("%d\n", i);
	n = z;
	printf("%u\n", n);
	printf("%d\n", n);
	printf("This is the float %f\n", f_var);
	printf("The rounding error is %f\n", (double)f_var - l_var);
	return (0);
}
