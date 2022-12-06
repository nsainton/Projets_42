/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:16:21 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/06 05:18:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>
int	main(void)
{
	int	i;

	i = printf("%%\n");
	i = ft_printf("%%\n");
	ft_printf("%d\n", i - 1);
	return (0);
}
