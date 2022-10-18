/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:28:59 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/18 18:19:06 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_buffer{
	char	buffer[BUFF_SIZE];
	ssize_t	n_read;
	size_t	index;
	size_t	line_index;
}				t_buffer;

void	ft_read(t_buffer *buff, int fd);

void	ft_fill_line(char *line, t_buffer *buff);

char	*ft_realloc(char *str, size_t size);

char	*ft_get_line(char *line, t_buffer *t_buff, int fd, size_t *length);

void	ft_reinit(t_buffer *t_buff);

char	*ft_get_next_line(int fd);
#endif
