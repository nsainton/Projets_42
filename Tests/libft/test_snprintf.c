/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_snprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 07:10:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/28 21:52:34 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/includes/libft.h"
#include <stdio.h>

int	main(void)
{
	char	s[30];
	char	d[10];
	char	e[10];
	int		i;
	int		j;

	*s = 0;
	ft_snprintf(s, 30, "Bonjour %d\n", 34);
	ft_printf("Test okay\n");
	ft_printf("%s", s);
	ft_snprintf(s, 30, "Bonjour %s", s);
	ft_printf("%s", s);
	i = ft_snprintf(d, 10, "%s", s);
	j = snprintf(e, 10, "%s", s);
	ft_printf("%s\n", d);
	ft_printf("ft_snprintf returned : %d\n", i);
	ft_printf("snprintf returned : %d\n", j);
	//ft_printf("%s\n", s);
	return (0);
}
