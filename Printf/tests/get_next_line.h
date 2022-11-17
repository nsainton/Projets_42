/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:45:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/15 23:53:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FILES FOPEN_MAX
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 123
# endif

char	*ft_get_line(char *line, char buff[BUFFER_SIZE], \
int fd, size_t *line_index);

char	*get_next_line(int fd);
#endif
