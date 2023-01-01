/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:11:00 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 01:28:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "librairies.h"
# include "typedefs.h"

typedef struct s_message
{
	int unsigned	bytes_received;
	t_byte			bit;
	t_byte			current_byte;
	t_str			message;
	int unsigned	message_length;
}				t_message;
#endif
