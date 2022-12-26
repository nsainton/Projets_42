/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:33:00 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 22:10:34 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

int	ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
