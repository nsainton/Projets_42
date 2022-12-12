/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:20:25 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/12 00:25:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "debug.h"
#include <stdio.h>
#include <string.h>

void	parse_test(char *str, char buf[BUFFER_SIZE + 1])
{
	t_gline	test;
	size_t	len;

	test.line_index = 0;
	test.line = str;
	len = strlen(str);
	printf("Voici la taille du buffer : %d\n", BUFFER_SIZE + 1);
	printf("Voici la string de depart: %s\n", test.line);
	printf("Voici sa longueur : %ld\n", len);
	parse_line(&test, buf, len);
	printf("Voici la nouvelle string : %s\n", str);
	print_buffer(buf);
	printf("Voici le nouvel index : %ld\n", test.line_index);
}

int	main(void)
{
	char	buf[BUFFER_SIZE + 1] = {0};

	parse_test("Bonjour\nCommentcava?", buf);
	return (0);
}
