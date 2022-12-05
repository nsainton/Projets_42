/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:58:02 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/04 22:10:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	max_int(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

t_ull	abs_ll(t_ll a)
{
	if (a < 0)
		return ((t_ull)(-1 * a));
	return ((t_ull)a);
}

t_ull	itou(int n)
{
	if (n < 0)
		return ((t_ull)(UINT_MAX + n + 1));
	return ((t_ull)n);
}

t_ull	lltoull(t_ll n)
{
	if (n < 0)
		return ((t_ull)(ULLONG_MAX + n + 1));
	return ((t_ull)n);
}
