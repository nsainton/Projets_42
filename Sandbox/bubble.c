/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:31:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/20 13:38:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	Bubble_sort(float arr[], int len)
{
	int	isSorted = 0;
	do
	{
		isSorted = 1;
		--len;
		float tmp;
		for (int i = 0; i < len; i ++)
			if (arr[i] > arr[i + 1])
			{
				printf("%d %d\n", i, i + 1);
				isSorted = 0;
				tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
	}while(! isSorted);
}

int	main(void)
{
	float arr[5] = {10, 8, 2, 4, 1};

	Bubble_sort(arr, 5);
	return (0);
}
