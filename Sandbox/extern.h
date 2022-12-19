/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:45:35 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/14 07:54:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERN_H
# define EXTERN_H
# include <unistd.h>
# if defined(__cplusplus)

extern "C" {
# endif

void foo();

#  if defined(__cplusplus)

}
#  endif
# endif
