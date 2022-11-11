/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:35:10 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/11 17:20:09 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int	printed;

	printed = printf("% d\n", 1232049);
	printf("Number of char printed with %%e: %d\n", printed - 1);
	printed = printf("%.12f\n", 12.34);
	printf("Number of char printed with %%f: %d\n", printed - 1);
	printed = printf("%#.10g\n", 0.0000123);
	printf("Number of char printed with %%g : %d\n", printed - 1);
	printf("With %%c : %c\n", 48);
	printf("%*d\n", 9, 2);
	return (0);
}
