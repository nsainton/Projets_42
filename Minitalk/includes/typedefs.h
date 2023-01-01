/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:10:09 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 07:43:17 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H
# include "librairies.h"

extern int					g_printed;

typedef char unsigned		t_byte;

typedef void				(*t_action)(int, siginfo_t *, void *);

typedef struct sigaction	t_sigaction;
#endif
