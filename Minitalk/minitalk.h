/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:09:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/31 23:05:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../Libft/includes/libft.h"
# include <signal.h>
# include <sys/types.h>

typedef char unsigned	t_byte;

typedef struct s_message
{
	int unsigned	bytes_received;
	t_byte			bit;
	t_byte			current_byte;
	t_str			message;
	int unsigned	message_length;
}				t_message;

void	print_bits(t_byte byte);
#endif
