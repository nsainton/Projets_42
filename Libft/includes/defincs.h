/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defincs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:01:59 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/23 19:15:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRAIRIES_H
# define LIBRAIRIES_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifdef FILES
#  undef FILES
# endif
# define FILES 123
# ifdef PBUFFER_SIZE
#  undef PBUFFER_SIZE
# endif
# define PBUFFER_SIZE 1000
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"
# define FLAGS "# +-0"
# define SPECIFIERS "cspdiuxX%"
#endif
