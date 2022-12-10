/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:29:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/08 07:16:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str, size_t old_size, size_t new_size)
{
	size_t	end_of_copy;
	size_t	index;
	char	*new_string;

	if (old_size < new_size)
		end_of_copy = old_size;
	else
		end_of_copy = new_size;
	new_string = malloc(sizeof *new_string * (new_size));
	if (new_string == NULL)
	{
		free(str);
		return (NULL);
	}
	index = 0;
	while (index < end_of_copy)
	{
		*(new_string + index) = *(str + index);
		index ++;
	}
	free(str);
	return (new_string);
}

void	ft_bzero(void *ptr, size_t bytes)
{
	char	*tmp_ptr;
	size_t	count;

	tmp_ptr = (char *)ptr;
	count = 0;
	while (count < bytes)
	{
		*(tmp_ptr + count) = 0;
		count ++;
	}
}

void	ft_memmove(void *destination, void *source, size_t bytes)
{
	size_t	count;
	int		direction;
	char	*dst;
	char	*src;
	
	count = 0;
	direction = 1;
	dst = (char *)destination;
	src = (char *)source;
	if (!bytes)
		return ;
	if (dst > src)
	{
		count = bytes - 1;
		direction = -1;
	}
	while (bytes > 0)
	{
		*(dst + count) = *(src + count);
		count += direction;
	}
}
	
void	ft_empty_buffer(char buf[BUFFER_SIZE], size_t index)
{
	ft_memmove(buf, buf + index, BUFFER_SIZE - index);
	ft_bzero(buf + BUFFER_SIZE - index, index);
}
