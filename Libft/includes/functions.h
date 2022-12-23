/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:39:08 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/23 19:24:59 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "defincs.h"
# include "structures.h"
# include "enums.h"
# include "typedefs.h"

//Functions from get_next_line_utils.c
int		ft_check_line(char buf[BUFFER_SIZE + 1], char *line, ssize_t n_read);

char	*get_next_line(int fd);

int		parse_line(t_gline *line, char buf[BUFFER_SIZE + 1], \
		const size_t bytes);

int		fill_line(t_gline *line, char buf[BUFFER_SIZE + 1]);

//Functions from allocation.c
void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_realloc(void *memzone, size_t old_size, size_t new_size);
#endif
