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

#ifndef FT_SSL_H
# define FT_SSL_H
# define USAGE "usage: ft_ssl command [-pqrc] [-s string] [file ...]\n"
# include "libft.h"

# define LEADING_ONE 0x80
# define F md5_f
# define G md5_g
# define H md5_h
# define I md5_i

typedef enum	e_hash_functions {
	NB_ALGOS = 2,
	MD5 = 0,
	SHA256
}				t_hash;

typedef struct	s_item {
	void			*content;
	size_t			size;
	struct s_item	*next;
}				t_item;

typedef struct	s_ssl {
	uint8_t			p:1;
	uint8_t			q:1;
	uint8_t			r:1;
	uint8_t			s:1;
	uint8_t			c:1;
	t_hash			h;
	t_item			*items;
}				t_params;

typedef union	u_md5_words {
	uint64_t		*uint64;
	uint32_t		*uint32;
	unsigned char	*uchar;
}				t_md5_words;

typedef struct	s_reg {
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
}				t_reg;

const uint32_t	g_add[64];
const uint32_t	g_shift[64];

void			*g_funcs[NB_ALGOS];
void			*g_originals[NB_ALGOS];

int				ssl_read_params(int ac, char **av, t_params *params);
void			ssl_clear_items(t_item **lst);
int				ssl_add_item_from_str(t_item **lst, char *str);
int				ssl_add_item_from_fd(t_item **lst, int fd);

uint32_t		lr(uint32_t x, uint32_t c);
uint32_t		rr(uint32_t x, uint32_t c);

char			*ssl_md5(unsigned char *input, size_t size);
unsigned char	*md5_original(void *data, size_t len);
void			md5_loop512(uint32_t *words, t_reg *r);
uint32_t		md5_f(uint32_t b, uint32_t c, uint32_t d);
uint32_t		md5_g(uint32_t b, uint32_t c, uint32_t d);
uint32_t		md5_h(uint32_t b, uint32_t c, uint32_t d);
uint32_t		md5_i(uint32_t b, uint32_t c, uint32_t d);

char			*ssl_sha256(unsigned char *input, size_t size);
unsigned char	*sha256_original(void *data, size_t len);
void			sha256_loop512(uint32_t *words, uint32_t r[8]);
uint32_t		sha256_ch(uint32_t b, uint32_t c, uint32_t d);
uint32_t		sha256_maj(uint32_t b, uint32_t c, uint32_t d);
uint32_t		sha256_bsig0(uint32_t b, uint32_t c, uint32_t d);
uint32_t		sha256_bsig1(uint32_t b, uint32_t c, uint32_t d);
uint32_t		sha256_ssig0(uint32_t b, uint32_t c, uint32_t d);
uint32_t		sha256_ssig1(uint32_t b, uint32_t c, uint32_t d);

#endif
