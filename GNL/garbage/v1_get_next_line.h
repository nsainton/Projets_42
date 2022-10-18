/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:02:00 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/17 19:17:13 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_buffer{
	char	buffer[BUFF_SIZE];
	ssize_t	n_read;
	size_t	index;
	size_t	line_index;
}				t_buffer;

void	ft_read_line(t_buffer *buf, int fd);

size_t	ft_strlen(const char *s);

void	ft_fill_line(char *line, t_buffer *buf);

char	*ft_realloc(char *line, size_t final_length);

void	ft_getline(char **line, t_buffer *buff, size_t *length, int fd);

char	*ft_get_next_line(int fd);

int		ft_newline(t_buffer *buff);
#endif
