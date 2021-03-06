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

static const uint32_t g_sha256_init_reg[8] =
{	0x6a09e667, 0xbb67ae85, 0x3c6ef372,
	0xa54ff53a, 0x510e527f, 0x9b05688c,
	0x1f83d9ab, 0x5be0cd19};

size_t			sha256_pad(t_md5_words **words, size_t size)
{
	size_t			new_size;
	t_md5_words		*tmp;

	if (!(tmp = malloc(sizeof(t_md5_words))))
		return (0);
	new_size = size + 1 + 8;
	while (new_size % 64)
		new_size++;
	if (new_size < size || !(tmp->uchar = ft_memalloc(new_size)))
		return (0);
	ft_memcpy(tmp->uchar, *words, size);
	tmp->uchar[size] = (uint8_t)LEADING_ONE;
	tmp->uint64[new_size / 8 - 1] = swap_endianess64(size * 8);
	*words = tmp;
	return (new_size);
}

char			*sha256_digest(uint32_t r[8])
{
	char		*res;
	const char	*base = "0123456789abcdef";
	int			i;
	uint8_t		*uchar;

	if (!(res = malloc(65)))
		return (NULL);
	i = -1;
	uchar = (uint8_t *)r;
	while (++i < 8)
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

void			sha256_copy_reg(uint32_t *src, uint32_t *dst)
{
	int i;

	i = -1;
	while (++i < 8)
		dst[i] = src[i];
}

void			sha256_update_reg(uint32_t *src, uint32_t *dst)
{
	int i;

	i = -1;
	while (++i < 8)
		dst[i] += src[i];
}

char			*ssl_sha256(unsigned char *input, size_t size)
{
	t_md5_words	*words;
	uint32_t	tmp[8];
	int			i;
	uint32_t	main_reg[8];

	words = (t_md5_words *)input;
	i = -1;
	if (!(size = sha256_pad(&words, size)))
		return (NULL);
	sha256_copy_reg((uint32_t *)g_sha256_init_reg, main_reg);
	i = -1;
	while (++i < (int)(size / 64))
	{
		sha256_copy_reg(main_reg, tmp);
		sha256_loop512(&words->uint32[i * 16], tmp);
		sha256_update_reg(tmp, main_reg);
	}
	free(words->uchar);
	free(words);
	return (sha256_digest(main_reg));
}
