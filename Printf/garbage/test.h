/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:07:58 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/04 23:13:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
#include "../includes/libftprintf.h"
#include <stdio.h>

void	print_flags(char flags[128]);

void	print_buffer(t_pbuffer *buf);

#endif
