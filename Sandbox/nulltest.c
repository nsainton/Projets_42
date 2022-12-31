/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nulltest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:42:16 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 00:43:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	printf("%ld\n", strlen(av[1]));
	return (0);
}
