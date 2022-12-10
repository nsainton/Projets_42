/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:57:49 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/10 05:04:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_buffer(char buf[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	write(1, "BUFFER\n", 7);
	while (buf[i] && i < BUFFER_SIZE)
	{
		write(1, buf + i, 1);
		i ++;
	}
	write(1, "\n", 1);
}
