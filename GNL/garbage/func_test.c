/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:20:25 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/13 02:27:48 by nsainton         ###   ########.fr       */
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

void	disp(char buf[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != '\n')
			write(1, buf + i, 1);
		else
			write(1, "_", 1);
		i ++;
	}
	write(1, "\n", 1);
}

void	fill_line_test(t_gline *line, char buf[BUFFER_SIZE + 1])
{
	print_buffer(buf);
	printf("Fill line : %d\n", fill_line(line, buf));
	printf("Voici la longueur de la ligne : %ld\n", line->line_index);
	printf("Voici la ligne : %s", line->line);
	free(line->line);
	print_buffer(buf);
}

int	main(void)
{
	char	buf[BUFFER_SIZE + 1] = {0};
	//char	str[] = "Bonjour\nCommentcava?";
	t_gline	line;

	ft_memmove(buf, "Bo\nnjour\nCommentca\nva?", BUFFER_SIZE);
	line.line = malloc(BUFFER_SIZE + 1);
	line.line_index = 0;
	fill_line_test(&line, buf);
	return (0);
}
