/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:12:40 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/22 21:17:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	test(a, b)
int	a;
float b;
{
	int	c;

	c = a * b > 0;
	return (c);
}

int	main(void)
{
	printf("%d\n", test(1, 2));
	return (0);
}
