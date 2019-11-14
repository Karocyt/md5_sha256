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
	MD5
}				t_hash;

typedef struct s_ssl {
	uint8_t	p:1;
	uint8_t	q:1;
	uint8_t	r:1;
	uint8_t	s:1;
	t_hash	h;
	void	(*f)(char *);
}				t_params;

typedef union u_ssl {
	t_params	opts;
	char	str[4];
}				t_uopts;

void *g_funcs[1];

int 			ft_ssl_process(int ac, char **av);
char 			*ft_md5(unsigned char *input, size_t size);





#endif