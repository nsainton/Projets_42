/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:13:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/16 15:46:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

typedef enum e_days
{
	F,
	T,
}	t_daus;
int	main(void)
{
	char	str[] = "Hey"
	" this really is"
	" true!!!";
	char	test = F;
	signed int		i = -1;
	int unsigned	limit = 200U;
	signed int		x;
	long			n = 30L;
	if 	(i < limit)
	{
		printf("OK\n");
		x = limit * n;
	}
	printf("%s\n", str);
	printf("%d\n", test);
	return (0);
}
