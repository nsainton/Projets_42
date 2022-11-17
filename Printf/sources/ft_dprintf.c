/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:37:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 02:44:01 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (printed);
}
