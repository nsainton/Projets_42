/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:23:38 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/02 09:09:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "Libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000000
# endif
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	line_index;
	int		width;
	int		prec;
}				t_buffer;

typedef long long int			t_ll;

typedef unsigned long long int	t_ull;

#endif
