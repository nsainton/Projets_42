/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:37:09 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 06:22:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_TYPEDEFS_H
# define LFT_TYPEDEFS_H

typedef long long int			t_ll;

typedef unsigned long long int	t_ull;

typedef void					(*t_pfunc)(t_pbuffer *, va_list *, char[128]);

typedef t_list					t_alloc;

typedef signed int				t_sint;

typedef unsigned int			t_uint;
#endif
