/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:32:51 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/23 19:16:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_pbuffer
{
	char		buffer[PBUFFER_SIZE];
	int			len;
	int			width;
	int			prec;
	intptr_t	fd;
	int			printed;
	char		str;
}				t_pbuffer;

typedef struct s_print
{
	char	modifier[3];
	char	beg;
	char	pad;
	char	align;
}				t_print;

typedef struct s_gline
{
	char	*line;
	size_t	line_index;
}				t_gline;

#endif
