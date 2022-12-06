/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:08:55 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/04 23:11:11 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test(char **conv)
{
	char		flags[128];
	t_pbuffer	buf;

	reset_flags(flags);
	print_flags(flags);
	buf.len = 0;
	buf.fd = 1;
	buf.printed = 0;
	parse_conv(&buf, conv, flags);
	print_buffer(&buf);
	print_flags(flags);
}
	

int	main(int ac, char **av)
{
	char	*tmp;

	if (ac != 2)
		return (1);
	tmp = av[1];
	test(&tmp);
	return (0);
}
