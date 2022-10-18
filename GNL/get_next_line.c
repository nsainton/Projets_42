/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:28:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/18 17:10:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_next_line(int fd)
{
	static t_buffer buff = {{0}, BUFF_SIZE, BUFF_SIZE, 0};
	char	*line;
	size_t	length;

	if (! buff.n_read)
		return (NULL);
	length = 1;
	line = (char *)malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	*line = 0;
	buff.line_index = 0;
	line = ft_get_line(line, &buff, fd, &length);
	if (line != NULL)
		line = ft_realloc(line, buff.line_index);
	printf("%s\n", line);
	sleep(2);
	return (line);
}
