/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:37:09 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 20:16:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef long long int			t_ll;

typedef unsigned long long int	t_ull;

typedef void					(*t_pfunc)(t_pbuffer *, va_list *, char[128]);

typedef t_list					t_alloc;
#endif
