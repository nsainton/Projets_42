/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:25:08 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/02 08:29:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_unsigned(t_ullong nbr, char **tab, char *base)
{
	if (nbr < ft_strlen(base))
	{
		**tab = *(base + nbr);
		*tab += 1;
	}
	else
	{
		put_unsigned(nbr / ft_strlen(base), tab, base);
		put_unsigned(nbr % ft_strlen(base), tab, base);
	}
}
