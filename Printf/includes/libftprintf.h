/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:25:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/15 16:14:32 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include "../Libft/libft.h"
# include <limits.h>

void	ft_putbase(long long int nbr, int maj, const char *base, size_t *printed);

size_t	ft_printmemory(void *p, int maj);
#endif
