/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:28:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/18 18:13:37 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_next_line(int fd)
{
	static t_buffer buff = {{0}, BUFF_SIZE, BUFF_SIZE, 0};
	char	*line;
	size_t	length;

	//printf("Reading the next line of the file\n");
	length = 1;
	line = (char *)malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	*line = 0;
	buff.line_index = 0;
	line = ft_get_line(line, &buff, fd, &length);
	if (line != NULL && length > 1)
		line = ft_realloc(line, buff.line_index);
	if (length == 1)
	{
		free(line);
		line = NULL;
	}
	if (line == NULL)
		ft_reinit(&buff);
//	printf("%s\n", line);
	return (line);
}
