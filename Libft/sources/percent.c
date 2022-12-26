/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:12:35 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:05:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	put_percent(t_pbuffer *buf, va_list *ap, char flags[128])
{
	(void)ap;
	(void)flags;
	add_char(buf, '%');
}
