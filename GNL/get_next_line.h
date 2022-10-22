/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:45:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/22 17:55:50 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FILES 123
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

char	*ft_get_line(char *line, char buff[BUFF_SIZE], int fd, size_t *line_index);

char	*ft_get_next_line(int fd);
#endif
