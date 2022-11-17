/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:25:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 02:50:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include "../Libft/libft.h"
# include <limits.h>
# include <stdarg.h>

int	ft_dprintf(int fd, const char *format, ...);

int	ft_printf(const char *format, ...);

int	ft_vdprintf(int fd, const char *format, va_list ap);

void	printf_printmemory(va_list ap, int *printed, int fd, char flag);

void	printf_putbase(long long int nbr, const char *base, \
int *printed, int fd);

void	printf_putstr(va_list ap, int *print, int fd, char flag);

void	printf_putchar(va_list ap, int *print, int fd, char flag);

void	printf_puthex_maj(va_list ap, int *print, int fd, char flag);

void	printf_puthex_min(va_list ap, int *print, int fd, char flag);

void	printf_putdec(va_list ap, int *print, int fd, char flag);

void	printf_percent(va_list ap, int *print, int fd, char flag);

void	printf_unsigned(va_list ap, int *print, int fd, char flag);
#endif
