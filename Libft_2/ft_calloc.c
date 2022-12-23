/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:55 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/10 13:14:42 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

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
	ft_memset(nptr, 0, nmemb * size);
	return (nptr);
}
