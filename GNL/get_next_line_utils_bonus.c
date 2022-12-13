/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:29:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/13 08:26:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_realloc(void *memzone, size_t old_size, size_t new_size)
{
	size_t	end_of_copy;
	void	*newzone;

	if (old_size < new_size)
		end_of_copy = old_size;
	else
		end_of_copy = new_size;
	newzone = malloc(new_size);
	if (newzone == NULL)
	{
		free(memzone);
		return (NULL);
	}
	ft_memmove(newzone, memzone, end_of_copy);
	free(memzone);
	return (newzone);
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

void	*ft_memmove(void *destination, const void *source, size_t bytes)
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
		return (destination);
	if (dst > src)
	{
		count = bytes - 1;
		direction = -1;
	}
	while (bytes > 0)
	{
		*(dst + count) = *(src + count);
		count += direction;
		bytes --;
	}
	return (destination);
}

int	ft_check_line(char buf[BUFFER_SIZE + 1], char *line, ssize_t n_read)
{
	if (! n_read)
	{
		buf[BUFFER_SIZE] = 1;
		if (! *line)
		{
			free(line);
			return (0);
		}
	}
	else if (line != NULL)
	{
		free(line);
		return (0);
	}
	return (1);
}
