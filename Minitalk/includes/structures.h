/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:11:00 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/09 02:56:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "librairies.h"
# include "typedefs.h"

typedef struct s_message
{
	t_byte	*str;
	size_t	len;
	t_byte	length;
	t_uint	bytes;
}				t_message;

typedef struct s_string_infos
{
	t_byte	*str;
	t_uint	bit;
	t_byte	len_sent;
	size_t	len;
}				t_string_infos;

#endif
