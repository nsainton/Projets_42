/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:45:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/20 00:40:37 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# define FILES 123
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_get_line(char *line, char buff[FILES][BUFF_SIZE], int fd, size_t *line_index);

char	*ft_get_next_line(int fd);

#endif
