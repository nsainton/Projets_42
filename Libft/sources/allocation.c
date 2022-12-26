/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:55 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:53:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nptr;

	if (!(nmemb && size))
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	nptr = malloc(nmemb * size);
	if (nptr == NULL)
		return (NULL);
	ft_memset(nptr, 0, size);
	return (nptr);
}

void	*ft_realloc(void *memzone, size_t old_size, size_t new_size)
{
	size_t	end_of_copy;
	void	*newzone;

	end_of_copy = ft_minst(old_size, new_size);
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
