/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:01:35 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 04:14:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Doesn't work
typedef struct s_test
{
	static struct s_test	*test;
	int						i;
	char					c;
}				t_test;
*/
/* Doesn't worl
void	static_increment(void);

int	main(void)
{
	static int	x = 0;

	static_increment();
	printf("%d\n", 0);
	return (0);
}

void	static_increment(void)
{
	x ++;
}
*/

/*
int	main(void)
{
	int	x;

	x = 0;
	printf("%d\n", (++x, x ++, 2));
	printf("%d\n", x);
	return (0);
}
*/

void	func(void)
{
	static char *s;

	if (s == NULL)
		printf("Bonjour\n");
}

int	main(void)
{
	func();
	return (0);
}
