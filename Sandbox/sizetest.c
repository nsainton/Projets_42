/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizetest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:34:48 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/22 22:38:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	//Not at all instructive
	int *ptr = malloc (10 * sizeof(int));
	if (!ptr)
		return (1);
	printf("This is the size of the memory zone : %zu\n", sizeof *ptr);
	printf("This is the size of the pointer : %ld\n", sizeof ptr);
	printf("An int after : %ld\n", sizeof *(ptr + 1));
	free(ptr);
	return (0);
}
