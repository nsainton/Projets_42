/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:57:49 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/12 00:26:11 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_buffer(char buf[BUFFER_SIZE + 1])
{
	write(1, "BUFFER\n", 7);
	write(1, buf, BUFFER_SIZE + 1);
	write(1, "\n", 1);
}
