/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 05:47:25 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 21:26:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	main(void)
{
	//Following initializations are equivalent
	/*
	int	arr[] = {1, 2, 3, 0};
	int arr2[4] = {1, 2, 3, 0, 5}; //Warning but it actually works
	int	arr3[] = {1, 2, 3, 0, };
	int	arr4[4] = {1, 2, 3};
	*/
	int	arr[2] = {1, 2};
	printf("%ld\n", sizeof(arr)/sizeof(*arr));
	//int	mat[][3]; Not working but dunno why
	extern int	mat[][3]; //This is working
	return (0);
}
