/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbuf_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:59:46 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/04 23:29:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

void	test(char *s)
{
	t_pbuffer	buf;

	init_pbuf(&buf, 5);
	if (s == NULL)
		return ;
	add_char(&buf, 'T');
	flush(&buf);
	while (*s)
	{
		add_char(&buf, *s);
		s ++;
		print_buffer(&buf);
		printf("--------------\n");
	}
	flush(&buf);
	printf("----------\n");
	print_buffer(&buf);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	test(av[1]);
	return (0);
}
