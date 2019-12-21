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
# define USAGE "usage: ft_ssl command [-pqr] [-s string] [file ...]\n"
# include "libft.h"

// (à partir du premier fichier ne prend que des fichiers)

typedef enum e_hash_functions {
	NB_ALGOS = 2,
	MD5 = 0,
	SHA256
}				t_hash;

typedef struct s_item {
	void			*content;
	size_t 			size;
	struct s_item	*next;
}				t_item;

typedef struct s_ssl {
	uint8_t			p;
	uint8_t			q;
	uint8_t			r;
	uint8_t			s;
	t_hash			h;
	t_item			*items;
}				t_params;

void *g_funcs[NB_ALGOS];

int 			ssl_process(t_params *params);
int 			ssl_read_params(int ac, char **av, t_params *params);
char 			*ssl_md5(unsigned char *input, size_t size);
char 			*ssl_sha256(unsigned char *input, size_t size);
void    		ssl_clear_items(t_item **lst);
int        		ssl_add_item_from_str(t_item **lst, char *str);
int        		ssl_add_item_from_fd(t_item **lst, int fd);





#endif