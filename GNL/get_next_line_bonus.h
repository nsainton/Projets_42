/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:12:33 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/13 09:14:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FILES 123
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gline
{
	char	*line;
	size_t	line_index;
}				t_gline;

void	*ft_realloc(void *memzone, size_t old_size, size_t new_size);

void	ft_bzero(void *ptr, size_t bytes);

void	*ft_memmove(void *destination, const void *source, size_t bytes);

int		ft_check_line(char buf[BUFFER_SIZE + 1], char *line, ssize_t n_read);

char	*get_next_line(int fd);

int		parse_line(t_gline *line, char buf[BUFFER_SIZE + 1], \
		const size_t bytes);

int		fill_line(t_gline *line, char buf[BUFFER_SIZE + 1]);
#endif
