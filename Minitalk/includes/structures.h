/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:11:00 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 04:26:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "librairies.h"
# include "typedefs.h"

typedef struct s_message
{
	int unsigned	bytes;
	t_byte			bit;
	t_byte			*message;
	int unsigned	length;
}				t_message;
#endif
