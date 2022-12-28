
#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "librairies.h"
# include "structures.h"
# include "enums.h"
# include "typedefs.h"

//Functions from address.c [       2 functions]

void	put_address(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from allocation.c [       2 functions]

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_realloc(void *memzone, size_t old_size, size_t new_size);

//Functions from ascii1.c [       5 functions]

int	ft_isalnum(int c);

int	ft_isascii(int c);

int	ft_isdigit(int c);

int	ft_isprint(int c);

int	ft_isspace(int c);

//Functions from ascii2.c [       5 functions]

int	ft_isupper(int c);

int	ft_islower(int c);

int	ft_isalpha(int c);

int	ft_tolower(int c);

int	ft_toupper(int c);

//Functions from decimal.c [       3 functions]

void	put_pos(t_ull nb, char **tab, char *base);

void	put_dec(t_pbuffer *buf, va_list *ap, char flags[128]);

void	put_unsigned(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from flush.c [       3 functions]

void	flush(t_pbuffer *buf);

void	flush_fd(t_pbuffer *buf);

void	flush_str(t_pbuffer *buf);

//Functions from ft_atoi.c [       1 functions]

int	ft_atoi(const char *nptr);

//Functions from ft_bzero.c [       1 functions]

void	ft_bzero(void *s, size_t n);

//Functions from ft_itoa.c [       3 functions]

char	*ft_itoa(int n);

//Functions from ft_printf.c [       3 functions]

int	ft_printf(const char *format, ...);

int	ft_dprintf(int fd, const char *format, ...);

int	ft_vdprintf(int fd, const char *format, va_list ap);

//Functions from ft_split.c [       4 functions]

char	**ft_split(char const *s, char c);

//Functions from ft_sprintf.c [       2 functions]

int	ft_snprintf(char *str, size_t size, const char *format, ...);

int	ft_vsnprintf(t_str *str, const char *format, va_list ap);

//Functions from ft_strchr.c [       1 functions]

char	*ft_strchr(const char *s, int c);

//Functions from ft_strdup.c [       1 functions]

char	*ft_strdup(const char *s);

//Functions from ft_striteri.c [       1 functions]

void	ft_striteri(char *s, void (*f) (unsigned int, char *));

//Functions from ft_strjoin.c [       1 functions]

char	*ft_strjoin(char const *s1, char const *s2);

//Functions from ft_strlcat.c [       1 functions]

size_t	ft_strlcat(char *dst, const char *src, size_t size);

//Functions from ft_strlcpy.c [       1 functions]

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//Functions from ft_strmapi.c [       1 functions]

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));

//Functions from ft_strncat.c [       1 functions]

size_t	ft_strncat(char *dest, const char *src, size_t n);

//Functions from ft_strncmp.c [       1 functions]

int	ft_strncmp(const char *s1, const char *s2, size_t n);

//Functions from ft_strnstr.c [       2 functions]

char	*ft_strnstr(const char *s1, const char *s2, size_t n);

//Functions from ft_strrchr.c [       1 functions]

char	*ft_strrchr(const char *s, int c);

//Functions from ft_strtrim.c [       2 functions]

char	*ft_strtrim(char const *s1, char const *set);

//Functions from ft_substr.c [       2 functions]

char	*ft_substr(char const *s, unsigned int start, size_t len);

//Functions from get_next_line.c [       5 functions]

int	parse_line(t_gline *line, char buf[BUFFER_SIZE + 1], const size_t bytes);

int	fill_line(t_gline *line, char buf[BUFFER_SIZE + 1]);

int	ft_check_line(char buf[BUFFER_SIZE + 1], char *line, ssize_t n_read);

char	*get_next_line(int fd);

//Functions from helpers.c [       5 functions]

int	max_int(int a, int b);

int	min_int(int a, int b);

t_ull	abs_ll(t_ll a);

t_ull	itou(int n);

t_ull	lltoull(t_ll n);

//Functions from hexadecimal.c [       5 functions]

void	put_hex_min(t_pbuffer *buf, va_list *ap, char flags[128]);

void	put_hex_maj(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from init.c [       4 functions]

void	init_pbuf_fd(t_pbuffer *buf, int fd);

void	init_pbuf_str(t_pbuffer *buf, t_str *str);

void	set_pad(char flags[128], t_print *pads);

void	init_func(t_pfunc func[128]);

//Functions from lst_addelem.c [       3 functions]

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new);

//Functions from lst_delelem.c [       2 functions]

void	ft_lstdelone(t_list *lst, void (*del) (void *));

void	ft_lstclear(t_list **lst, void (*del) (void *));

//Functions from lst_functions.c [       4 functions]

int	ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstiter(t_list *lst, void (*f) (void *));

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));

//Functions from memfuncs.c [       5 functions]

void	*ft_memchr(const void *s, int c, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *b, int c, size_t len);

//Functions from minimum.c [       3 functions]

signed int	ft_minint(signed int a, int signed b);

unsigned int	ft_minuint(unsigned int a, unsigned int b);

size_t	ft_minst(size_t a, size_t b);

//Functions from parsing.c [       2 functions]

void	parse_conv(int *width, int *prec, const char **conv, char flags[128]);

void	loop(t_pbuffer *buf, const char **conv);

//Functions from pbuffer.c [       4 functions]

void	add_char(t_pbuffer *buf, char c);

void	add_nchar(t_pbuffer *buf, char c, int n);

void	add_str(t_pbuffer *buf, char *str);

void	add_nstr(t_pbuffer *buf, char *str, int n);

//Functions from percent.c [       1 functions]

void	put_percent(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from print_fd.c [       4 functions]

int	ft_putchar_fd(char c, int fd);

int	ft_putstr_fd(char *s, int fd);

int	ft_putendl_fd(char *s, int fd);

int	ft_putnbr_fd(int n, int fd);

//Functions from printing.c [       2 functions]

void	build_res(t_pbuffer *buf, char *res, char flags[128], int len);

void	print_res(t_pbuffer *buf, char *res, int len, t_print *pads);

//Functions from putnbr_tab.c [       2 functions]

void	put_uns_tab(t_ull nb, char **tab, char *base, size_t len);

void	put_nb_tab(t_ll nb, char *tab, char *base);

//Functions from strings.c [       3 functions]

void	put_char(t_pbuffer *buf, va_list *ap, char flags[128]);

void	put_string(t_pbuffer *buf, va_list *ap, char flags[128]);

//Functions from strlength.c [       2 functions]

size_t	ft_strlen(const char *s);

size_t	ft_strnlen(const char *s, size_t maxlen);

//Functions from tstr_add.c [       2 functions]

int	tstr_addchar(t_str *str, char c);

int	tstr_addstr(t_str *str, const t_str *toadd);

//Functions from tstr_del.c [       1 functions]

void	tstr_del(t_str *str);

//Functions from tstr_init.c [       3 functions]

void	tstr_init(t_str *str);

int	tstr_initstr(t_str *tstr, char *str, size_t buffsize);

int	tstr_cpy(t_str *dst, const t_str *src);

#endif
