/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:22:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:53:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

signed int	ft_minint(signed int a, int signed b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned int	ft_minuint(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_minst(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
