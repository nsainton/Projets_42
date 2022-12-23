/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpymove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:36:43 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 12:53:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"
#define DT 5
#define SR 0

int	main(void)
{
	//char	src[100] = "Bien le bonjour";
	char	dst_cpy[100] = "0123456789";
	char	dst_mv[100] = "0123456789";

	printf("%s\n%s\n", (char *)ft_memmove((void *)(dst_mv + DT), (void *)(dst_mv + SR), 10), dst_mv);
	printf("%s\n%s\n", (char *)ft_memcpy((void *)(dst_cpy + DT), (void *)(dst_cpy + SR), 10), dst_cpy);
	printf("%ld\n", ft_strlen("Bonjour, comment ca va ?"));
	return (0);
}
