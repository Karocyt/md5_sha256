/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/03 16:03:21 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE				7
# define FT_TRUE				1
# define FT_FALSE				0
# define FT_SUCCESS				1
# define FT_FAILURE				0
# define FT_INFINITY			1.0 / 0.0
# define FT_NOT_A_NUMBER		FT_INFINITY - FT_INFINITY
# define PF_FLAGS				"I'#0+- "
# define PF_LMODIF				"hljz"
# define PF_CONV				"dDioOuUxXcCsSp%B"
# define PF_BASE				"0123456789abcdef"
# define MALLOC_FAILED			"Error: failed malloc\n"
# define RED					"\033[31m"
# define GREEN					"\033[32m"
# define EOC					"\033[0m"
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <sys/mman.h>
# include <limits.h>

typedef int8_t	t_bool;
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** PRINTF
*/

typedef struct	s_pattern
{
	unsigned char	htag_flag : 1;
	unsigned char	plus_flag : 1;
	unsigned char	minus_flag : 1;
	unsigned char	zero_flag : 1;
	unsigned char	space_flag : 1;
	unsigned char	min_field;
	unsigned char	precision;
	unsigned char	hh_lmodif : 1;
	unsigned char	h_lmodif : 1;
	unsigned char	l_lmodif : 1;
	unsigned char	ll_lmodif : 1;
	unsigned char	j_lmodif : 1;
	unsigned char	z_lmodif : 1;
	unsigned char	precision_0 : 1;
	unsigned char	null : 1;
	unsigned char	conv;
	unsigned char	neg : 1;
	int				len;
	short int		char_0 : 1;
	long long		ret;
	char			*res;
}				t_pattern;

int				ft_printf(const char *input, ...);
char			*ft_spf(const char *input, ...);
char			*ft_vspf(const char *input, va_list ap);
int				ft_fprintf(int fd, const char *input, ...);
int				ft_vprintf(const char *input, va_list ap);
int				ft_main_printf(char **res, const char *input, va_list ap);
t_pattern		*ft_b(char *str, va_list ap);
char			*ft_append_conv(char **res, char *start, va_list ap);
void			ft_free_patt(t_pattern **patt);
int				ft_apply_fmt(t_pattern *patt, va_list ap);
void			*ft_strset(char *b, int c, size_t len);
void			ft_fmt_d(t_pattern *patt, va_list ap);
void			ft_fmt_c(t_pattern *patt, va_list ap);
int				ft_detect_int_pattern(char *str);
char			*ft_pad(char *str, size_t minlen, char c, int right_padded);
void			ft_fmt_s(t_pattern *patt, va_list ap);
void			ft_fmt_b(t_pattern *patt, va_list ap);
int				ft_set_flags(t_pattern *patt, char **str);
int				pf_ispatt(t_pattern *patt, char **str, int *i, va_list ap);
char			*ft_str_merge_to_next_patt(char **s1, char *s2);
void			ft_append_patt(t_pattern *patt, char **str, int *ret);
int				gnl_append_read(char **stack, int fd);

/*
** MEMORY
*/

long int		ft_free_ret(void *p, int r);
void			*ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *destination, const void *source, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memclear(void *s, size_t n);
void			*ft_realloc2(void *old, size_t old_size, size_t new_size);
void			ft_swap(void *a, void *b);
void			ft_free_strs(int nb, ...);
void			ft_memrev(void *ptr, int size);
char			*ft_memcatdup(char *s1, char *s2, int size1, int size2);

/*
** STRINGS MANIPULATION
*/

char			*ft_strnew(size_t size);
size_t			ft_strlen(char *str);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
char			*ft_strdup(char *src);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strndups(const char *src, size_t n);
char			*ft_strcatdup(char *s1, char *s2);
char			*ft_strrev(char *str);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, size_t n);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
char			*ft_strcat(char *dest, char *src);
unsigned int	ft_strlcat(char *dest, char *src, size_t size);
char			*ft_strncat(char *dest, char *src, size_t size);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strmap(char const *s, char (*f)(char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_putendl(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_strtrimc(char const *s, char c);
char			*ft_strtoupper(char *str);
size_t			ft_wordscount(char *str);
char			*ft_replace_str(char *old, char *new);
char			ft_strpop(char **str);
void			ft_prepend_char(char **s, char chr);
void			ft_append_char(char **s, char chr);
void			*ft_strset(char *b, int c, size_t len);
char			**ft_split(char *str, char *chars);
char			*ft_str_merge(char **s1, char *s2);

/*
** UTF-8
*/

char			*ft_utf8_strncpy(char *dest, char *src, size_t n);
char			*ft_utf8_strndup(const char *src, size_t n);

/*
** WIDE STRINGS
*/

int				ft_wclen(wchar_t c);
int				ft_wctomb(char *mbs, wchar_t c);
int				ft_wcstombs(char **res, wchar_t *wcs);
void			ft_putwstr(wchar_t *str);
wchar_t			*ft_wstrdup(wchar_t *src);
size_t			ft_wstrlen(wchar_t *src);
wchar_t			*ft_wstrcpy(wchar_t *dest, wchar_t *src);
wchar_t			*ft_strtowstr(char *src);
wchar_t			*ft_replace_wstr(wchar_t *old, wchar_t *new);
void			ft_prepend_wchar_t(wchar_t **s, wchar_t chr);
wchar_t			*ft_wstrcatdup(wchar_t *s1, wchar_t *s2);
wchar_t			ft_wstrpop(wchar_t **str);
wchar_t			*ft_wstrcatdup(wchar_t *s1, wchar_t *s2);
wchar_t			*ft_wstrcat(wchar_t *dest, wchar_t *src);
wchar_t			*ft_wstrcap(wchar_t *str);
wchar_t			*ft_wstrtoupper(wchar_t *str);
wchar_t			*ft_wstrchr(const wchar_t *s, int c);
wchar_t			*ft_wstrndup(const wchar_t *src, size_t n);
wchar_t			*ft_wstrncpy(wchar_t *dest, wchar_t *src, size_t n);

/*
** INT ARRAYS
*/

int				ft_ptrarrlen(void *arr);
size_t			ft_indexof(int needle, int *haystack, size_t haystack_size);
void			ft_sort_int_array(int *tab, int size);
int				ft_iter(char *str, void *ft_check_f(int c));
int				ft_intarrlen(int *arr);

/*
** GRIDS
*/

int				ft_free_grid(char ***tab);
void			ft_print_grid(char **grid);
char			**ft_new_grid(int lines, int cols, char c);

/*
** CHARS CHECK / CONVERT
*/

int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isgraph(int c);
int				ft_isspace(char c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isxdigit(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_ispunct(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_isalldigit(char *str);
int				ft_getchar_pos(char *str, int c);

/*
** TYPE CONVERT
*/

long long		ft_atoi(char *str);
char			*ft_itoa(long long nb);
double			ft_atof(const char *nptr);
char			*ft_lsttostr(t_list *begin);
char			*ft_uitoa_base(unsigned long long nbr, int base);
char			*ft_itoa_base(long long nbr, int base);
long long		ft_watoi(wchar_t *str);

/*
** I/O
*/

char			**ft_get_txtfile(char *filename);
long int		ft_get_fd_content(unsigned char **res, int fd);
void			ft_putchar(unsigned int c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putnbr_base(long long nb, int base);
void			ft_putnbr_ubase_limit(unsigned long long nb, size_t obase,
					int limit);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int nb, int fd);

/*
** MATHS
*/

int				ft_fact(int nb);
int				ft_pow(int nb, int power);
int				ft_sqrt(int nb);
int				ft_isprime(int nb);
int				ft_abs(int nb);
double			ft_powf(double nb, short power);

/*
** LISTS
*/

size_t			ft_lstlen(void *lst, void *ptr_function(void *));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstappend(t_list **list, t_list *new);
void			ft_lstmerge(t_list **list1, t_list *list2);
size_t			ft_lstsize(t_list *begin_list);
t_list			*ft_lstlast(t_list *begin_list);
void			ft_lstrev(t_list **begin_list);
t_list			*ft_lstat(t_list *begin_list, unsigned int nbr);
t_list			*ft_lstfind(t_list *begin_list, void *data_ref,
							int (*cmp)());
void			ft_lstiterif(t_list *begin_list, void (*f)(void *),
							void *data_ref, int (*cmp)());
void			ft_lstdelval(t_list **begin_list, void *data_ref,
							int (*cmp)());
char			*ft_lsttostr(t_list *current);
t_list			*ft_strtolst(char *str);
void			ft_free_tlist(t_list **list);
/*
** void			ft_lstsort(t_list **begin_list, int (*cmp)());
*/

/*
** FILES
*/

int				get_next_line(const int fd, char **line);

/*
** ERROR MANAGEMENT
*/

long long		ft_error(char *s, long long return_val);

/*
** TO CONVERT
*/

t_list			*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
t_list			*ft_list_push_params(int ac, char **av);
void			ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
					void *data_ref, int (*cmp)());

#endif
