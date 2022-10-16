/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:22:22 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/16 20:23:22 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char		buffer[BUFF_SIZE] = {0};
	static size_t	index = BUFF_SIZE;
	char			*line;
	size_t			n_read;

	if (index == BUFF_SIZE)
		n_read = read(fd, buffer, BUFF_SIZE);
	if (n_read == -1)
		return (NULL);
}

size_t	ft_getline(char *buf, size_t start, size_t size)
{
	if (start == size)
		return 
