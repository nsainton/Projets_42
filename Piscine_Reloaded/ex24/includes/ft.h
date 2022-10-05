/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:39:27 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 23:12:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stddef.h>

void	ft_putchar(char c);

void	ft_swap(int *a, int *b);

void	ft_putstr(char *str);

int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2);

#endif
