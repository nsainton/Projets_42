/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:23:38 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 04:05:55 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../Libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# ifndef PBUFFER_SIZE
#  define PBUFFER_SIZE 1000
# endif
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"
# define FLAGS "# +-0."
# define SPECIFIERS "cspdiuxX%"

typedef struct s_pbuffer
{
	char	buffer[PBUFFER_SIZE];
	int		len;
	int		width;
	int		prec;
	int		fd;
	int		printed;
}				t_pbuffer;

typedef struct s_print
{
	char	modifier[2];
	char	beg;
	char	pad;
	char	align;
}				t_print;

typedef long long int			t_ll;

typedef unsigned long long int	t_ull;

typedef void					(*t_pfunc)(t_pbuffer *, va_list *, char[128]);

//Functions from parsing.c
void	parse_conv(t_pbuffer *buf, const char **conv, char flags[128]);

void	loop(t_pbuffer *buf, const char **conv);

//Functions from init.c
void	reset_flags(char flags[128]);

void	init_pbuf(t_pbuffer *buf, int fd);

void	set_pad(t_pbuffer *buf, char flags[128], t_print *pads);

void	init_func(t_pfunc func[128]);

//Functions from pbuffer.c
void	flush(t_pbuffer *buf);

void	add_char(t_pbuffer *buf, char c);

void	add_nchar(t_pbuffer *buf, char c, int n);

void	add_str(t_pbuffer *buf, char *str);

void	add_nstr(t_pbuffer *buf, char *str, int n);

//Functions from helpers.c
int		max_int(int a, int b);

t_ull	abs_ll(t_ll a);

t_ull	itou(int n);

t_ull	lltoull(t_ll n);

//Functions from decimal.c
void	put_unsigned(t_ull nb, char **tab, char *base);

void	put_dec(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from char.c
void	put_char(t_pbuffer *buf, va_list *ap, char flags[128]);

// Functions from printing.c
void	build_res(t_pbuffer *buf, char *nb, char flags[128], int len);

void	print_res(t_pbuffer *buf, char *nb, int len, t_print *pads);

//Functions from ft_printf.c
int		ft_printf(const char *format, ...);

int		ft_dprintf(int fd, const char *format, ...);

int		ft_vdprintf(int fd, const char *format, va_list ap);

#endif
