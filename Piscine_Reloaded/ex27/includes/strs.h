/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:56:34 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/06 00:57:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRS_H
# define STRS_H
# include <unistd.h>
# include <stddef.h>

int		ft_strlen(char *str);

void	ft_putstr(int fd, char *str);

#endif
