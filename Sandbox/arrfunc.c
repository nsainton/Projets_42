/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:21:17 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/22 22:25:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	test(int array[static 3], int size)
{
	array[0] = size;
	return (1);
}

int	main(void)
{
	int	*arr;
	arr = malloc (3 * sizeof *arr);

	test(arr, 4);
	return (0);
}
