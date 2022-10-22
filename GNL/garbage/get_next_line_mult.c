/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mult.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:28:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/19 16:58:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_mult.h"

char	*ft_get_next_line(int fd)
{
	static t_buffer	buff = {{{0}, {0}}, BUFF_SIZE, BUFF_SIZE, 0};
	char			*line;
	size_t			length;

	if (fd > FILES - 1)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	length = 1;
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
	return (line);
}
