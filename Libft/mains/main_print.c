/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:44:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/08 10:24:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		printf("%d\n", ft_isprint(*(*(av + i))));
		i ++;
	}
	return (0);
}
