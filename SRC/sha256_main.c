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

#include "ft_ssl.h"

/*
**	https://tools.ietf.org/html/rfc4634
**	http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf
**	https://en.wikipedia.org/wiki/SHA-2
*/

const t_reg g_sha256_init_reg = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};

size_t	sha256_pad(t_md5_words **words, size_t size)
{
	size_t			new_size;
	t_md5_words		*tmp;

	if (!(tmp = malloc(sizeof(t_md5_words))))
		return (0);
	new_size = size + 1 + 8;
	while (new_size % 64)
		new_size++;
	if (new_size < size || !(tmp->uchar = ft_memalloc(new_size))) // MALLOC
		return (0);
	ft_memcpy(tmp->uchar, *words, size);
	tmp->uchar[size] = (uint8_t)LEADING_ONE;
	tmp->uint64[new_size / 8 - 1] = size * 8;
	*words = tmp;
	return (new_size);
}

char	*sha256_digest(t_reg r)
{
	char		*res;
	const char	*base = "0123456789abcdef";
	int			i;
	uint8_t		*uchar;

	if (!(res = ft_memalloc(65)))
		return (NULL);
	i = -1;
	uchar = (uint8_t *)&r;
	while (++i < 2)//64)
	{
		res[i * 8] = base[uchar[i * 4 + 3] / 16];
		res[i * 8 + 1] = base[uchar[i * 4 + 3] % 16];
		res[i * 8 + 2] = base[uchar[i * 4 + 2] / 16];
		res[i * 8 + 3] = base[uchar[i * 4 + 2] % 16];
		res[i * 8 + 4] = base[uchar[i * 4 + 1] / 16];
		res[i * 8 + 5] = base[uchar[i * 4 + 1] % 16];
		res[i * 8 + 6] = base[uchar[i * 4] / 16];
		res[i * 8 + 7] = base[uchar[i * 4] % 16];
	}
	res[64] = 0;
	return (res);
}

char	*ssl_sha256(unsigned char *input, size_t size)
{
	t_md5_words	*words;
	t_reg		tmp;
	int			iter;
	int			i;
	t_reg		main_reg;

	words = (t_md5_words *)input;
	if (!(size = sha256_pad(&words, size)))
		return (NULL);
	iter = size / 64;
	i = -1;
	main_reg = g_sha256_init_reg;
	while (++i < iter)
	{
		tmp = main_reg;
		md5_loop512(&words->uint32[i * 16], &tmp);
		main_reg.a += tmp.a;
		main_reg.b += tmp.b;
		main_reg.c += tmp.c;
		main_reg.d += tmp.d;
	}
	free(words->uchar);
	free(words);
	return (sha256_digest(main_reg));
}
