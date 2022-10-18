/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:28:59 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/18 21:57:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FILES 123
# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer{
	char	buffer[FILES][BUFF_SIZE];
	ssize_t	n_read;
	size_t	index;
	size_t	line_index;
}				t_buffer;

char	*ft_realloc(char *str, size_t size);

char	*ft_get_line(char *line, t_buffer *t_buff, int fd, size_t *length);

void	ft_reinit(t_buffer *t_buff);

char	*ft_get_next_line(int fd);
#endif
