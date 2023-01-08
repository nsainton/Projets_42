/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:11:00 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/08 02:26:31 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "librairies.h"
# include "typedefs.h"

typedef struct s_byte_count
{
	t_uint	bytes;
	t_byte	bit;
}				t_byte_count;

typedef struct s_message
{
	t_byte_count	byte;
	t_byte			*message;
	t_uint			length;
}				t_message;
#endif
