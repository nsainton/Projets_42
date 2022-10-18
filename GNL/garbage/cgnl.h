/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgnl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:28:59 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/17 19:30:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer{
	char	buffer[BUFF_SIZE];
	ssize_t	n_read;
	size_t	index;
	size_t	line_index;
}				t_buffer;

#endif
