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
**  https://tools.ietf.org/html/rfc4634
**  http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf
**  https://en.wikipedia.org/wiki/SHA-2
*/

static const uint32_t g_sha256_init_reg[8] = {
	0xc1059ed8, 0x367cd507, 0x3070dd17,
	0xf70e5939, 0xffc00b31, 0x68581511,
	0x64f98fa7, 0xbefa4fa4};

char			*sha224_digest(uint32_t r[8])
{
	char		*res;
	const char	*base = "0123456789abcdef";
	int			i;
	uint8_t		*uchar;

	if (!(res = malloc(65)))
		return (NULL);
	i = -1;
	uchar = (uint8_t *)r;
	while (++i < 7)
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

char			*ssl_sha224(unsigned char *input, size_t size)
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
	return (sha224_digest(main_reg));
}
