/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 05:03:22 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 06:51:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char	*s = "bonjour";
	char	n[7];
	int		i;
	int		len;

	i = printf("%- 12s\n", s);
	printf("%d\n", i);
	*n = 0;
	len = (int)ft_strlcat(n, "(null)", 7);
	printf("len : %d\n", len);
	printf("chaine : %s\n", n);
	return (0);
}
