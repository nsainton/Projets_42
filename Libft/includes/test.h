/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:39:22 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/23 21:40:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "libft.h"
//Functions from address.c 
static void                          build_address(t_pbuffer *buf, va_list *ap, char res[19], int *len);
void                                 put_address(t_pbuffer *buf, va_list *ap, char flags[128]);
//Functions from allocation.c 
void                                 *ft_calloc(size_t nmemb, size_t size);
void                                 *ft_realloc(void *memzone, size_t old_size, size_t new_size);
//Functions from decimal.c 
void                                 put_pos(t_ull nb, char **tab, char *base);
void                                 put_dec(t_pbuffer *buf, va_list *ap, char flags[128]);
void                                 put_unsigned(t_pbuffer *buf, va_list *ap, char flags[128]);
//Functions from flush.c 
void                                 flush(t_pbuffer *buf);
void                                 flush_fd(t_pbuffer *buf);
//Functions from ft_atoi.c 
static int                           ft_isspace(int c);
int                                  ft_atoi(const char *nptr);
//Functions from ft_bzero.c 
void                                 ft_bzero(void *s, size_t n);
//Functions from ft_isalnum.c 
int                                  ft_isalnum(int c);
//Functions from ft_isalpha.c 
static int                           ft_isupper(int c);
static int                           ft_islower(int c);
int                                  ft_isalpha(int c);
//Functions from ft_isascii.c 
int                                  ft_isascii(int c);
//Functions from ft_isdigit.c 
int                                  ft_isdigit(int c);
//Functions from ft_isprint.c 
int                                  ft_isprint(int c);
//Functions from ft_itoa.c 
static size_t                        ft_digits(int n);
static void                          ft_itoa_rec(int n, char *number, int *index);
char                                 *ft_itoa(int n);
//Functions from ft_lstadd_back.c 
void                                 ft_lstadd_back(t_list **lst, t_list *new);
//Functions from ft_lstadd_front.c 
void                                 ft_lstadd_front(t_list **lst, t_list *new);
//Functions from ft_lstclear.c 
void                                 ft_lstclear(t_list **lst, void (*del) (void *));
//Functions from ft_lstdelone.c 
void                                 ft_lstdelone(t_list *lst, void (*del) (void *));
//Functions from ft_lstiter.c 
void                                 ft_lstiter(t_list *lst, void (*f) (void *));
//Functions from ft_lstlast.c 
t_list                               *ft_lstlast(t_list *lst);
//Functions from ft_lstmap.c 
t_list                               *ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));
//Functions from ft_lstnew.c 
t_list                               *ft_lstnew(void *content);
//Functions from ft_lstsize.c 
int                                  ft_lstsize(t_list *lst);
//Functions from ft_memchr.c 
void                                 *ft_memchr(const void *s, int c, size_t n);
//Functions from ft_memcmp.c 
int                                  ft_memcmp(const void *s1, const void *s2, size_t n);
//Functions from ft_memcpy.c 
void                                 *ft_memcpy(void *dest, const void *src, size_t n);
//Functions from ft_memmove.c 
void                                 *ft_memmove(void *dest, const void *src, size_t n);
//Functions from ft_memset.c 
void                                 *ft_memset(void *b, int c, size_t len);
//Functions from ft_printf.c 
int                                  ft_printf(const char *format, ...);
int                                  ft_dprintf(int fd, const char *format, ...);
int                                  ft_vdprintf(int fd, const char *format, va_list ap);
//Functions from ft_putchar_fd.c 
int                                  ft_putchar_fd(char c, int fd);
//Functions from ft_putendl_fd.c 
int                                  ft_putendl_fd(char *s, int fd);
//Functions from ft_putnbr_fd.c 
static void                          ft_fill_string(char *string, int nbr, int *index);
int                                  ft_putnbr_fd(int n, int fd);
//Functions from ft_putstr_fd.c 
int                                  ft_putstr_fd(char *s, int fd);
//Functions from ft_split.c 
char                                 **ft_split(char const *s, char c);
//Functions from ft_strchr.c 
char                                 *ft_strchr(const char *s, int c);
//Functions from ft_strdup.c 
char                                 *ft_strdup(const char *s);
//Functions from ft_striteri.c 
void                                 ft_striteri(char *s, void (*f) (unsigned int, char *));
//Functions from ft_strjoin.c 
char                                 *ft_strjoin(char const *s1, char const *s2);
//Functions from ft_strlcat.c 
size_t                               ft_strlcat(char *dst, const char *src, size_t size);
//Functions from ft_strlcpy.c 
size_t                               ft_strlcpy(char *dst, const char *src, size_t size);
//Functions from ft_strlen.c 
size_t                               ft_strlen(const char *s);
//Functions from ft_strmapi.c 
char                                 *ft_strmapi(char const *s, char (*f) (unsigned int, char));
//Functions from ft_strncat.c 
char                                 *ft_strncat(char *dest, const char *src, size_t n);
//Functions from ft_strncmp.c 
int                                  ft_strncmp(const char *s1, const char *s2, size_t n);
//Functions from ft_strnlen.c 
size_t                               ft_strnlen(const char *s, size_t maxlen);
//Functions from ft_strnstr.c 
char                                 *ft_strnstr(const char *s1, const char *s2, size_t n);
//Functions from ft_strrchr.c 
char                                 *ft_strrchr(const char *s, int c);
//Functions from ft_strtrim.c 
static int                           ft_in(char c, char const *set);
char                                 *ft_strtrim(char const *s1, char const *set);
//Functions from ft_substr.c 
static size_t                        ft_min(const char *s, unsigned int start, size_t len);
char                                 *ft_substr(char const *s, unsigned int start, size_t len);
//Functions from ft_tolower.c 
int                                  ft_tolower(int c);
//Functions from ft_toupper.c 
int                                  ft_toupper(int c);
//Functions from get_next_line.c 
int                                  parse_line(t_gline *line, char buf[BUFFER_SIZE + 1], const size_t bytes);
int                                  fill_line(t_gline *line, char buf[BUFFER_SIZE + 1]);
static int                           read_line(t_gline *line, char buf[BUFFER_SIZE + 1], const int fd);
int                                  ft_check_line(char buf[BUFFER_SIZE + 1], char *line, ssize_t n_read);
char                                 *get_next_line(int fd);
//Functions from helpers.c 
int                                  max_int(int a, int b);
int                                  min_int(int a, int b);
t_ull                                abs_ll(t_ll a);
t_ull                                itou(int n);
t_ull                                lltoull(t_ll n);
//Functions from hexadecimal.c 
static void                          set_hpad(char res[19], char flags[128], t_print *pads, char min);
static void                          build_hres(t_pbuffer *buf, char res[19], char flags[128], char min);
static void                          put_hex(t_pbuffer *buf, va_list *ap, char flags[128], char min);
void                                 put_hex_min(t_pbuffer *buf, va_list *ap, char flags[128]);
void                                 put_hex_maj(t_pbuffer *buf, va_list *ap, char flags[128]);
//Functions from init.c 
void                                 init_pbuf_fd(t_pbuffer *buf, int fd);
void                                 set_pad(char flags[128], t_print *pads);
void                                 init_func(t_pfunc func[128]);
//Functions from parsing.c 
void                                 parse_conv(int *width, int *prec, const char **conv, char flags[128]);
void                                 loop(t_pbuffer *buf, const char **conv);
//Functions from pbuffer.c 
void                                 add_char(t_pbuffer *buf, char c);
void                                 add_nchar(t_pbuffer *buf, char c, int n);
void                                 add_str(t_pbuffer *buf, char *str);
void                                 add_nstr(t_pbuffer *buf, char *str, int n);
//Functions from percent.c 
void                                 put_percent(t_pbuffer *buf, va_list *ap, char flags[128]);
//Functions from printing.c 
void                                 build_res(t_pbuffer *buf, char *res, char flags[128], int len);
void                                 print_res(t_pbuffer *buf, char *res, int len, t_print *pads);
//Functions from strings.c 
static void                          set_len(t_pbuffer *buf, char flags[128], int *len, char *res);
void                                 put_char(t_pbuffer *buf, va_list *ap, char flags[128]);
void                                 put_string(t_pbuffer *buf, va_list *ap, char flags[128]);
#endif
