/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:54:19 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/20 14:45:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		i;
	char	*s;

	i = 0;
	while (s = malloc(1), i < 10) //Does not comply with 42 norm
	{
		printf("%d\n", i++);
		free(s);
	}
	if (s)
		free(s);
	if (i > 0)
	if (i % 2)
	printf("Positive and Odd\n");
	else
	printf("Positive and Even\n");
	return (0);
}
