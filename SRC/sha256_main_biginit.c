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

// static const uint32_t g_sha224_init_reg[8] = {0xc1059ed8, 0x367cd507, 0x3070dd17,
//                                      0xf70e5939, 0xffc00b31, 0x68581511,
//                                      0x64f98fa7, 0xbefa4fa4};

// static const uint32_t g_sha256_init_reg[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372,
//                                          0xa54ff53a, 0x510e527f, 0x9b05688c,
//                                          0x1f83d9ab, 0x5be0cd19};

// Big-endian version:
static const uint32_t g_sha256_init_reg[8] = {0x67e6096a, 0x85ae67bb, 0x72f36e3c,
                                        0x3af54fa5, 0x7f520e51, 0x8c68059b,
                                        0xabd9831f, 0x19cde05b};

static size_t   sha256_pad(t_md5_words **words, size_t size)
{
    size_t          new_size;
    t_md5_words     *tmp;

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

static void sha256_copy_reg(uint32_t *src, uint32_t *dst)
{
    int i;

    i = -1;
    while (++i < 8)
        dst[i] = src[i];
}

static void sha256_update_reg(uint32_t *src, uint32_t *dst)
{
    int i;

    i = -1;
    while (++i < 8)
        dst[i] += src[i];
}

char    *ssl_sha256_biginit(unsigned char *input, size_t size)
{
    t_md5_words *words;
    uint32_t    tmp[8];// = malloc(4 * 8);//[8];
    int         i;
    uint32_t    main_reg[8];

    // rotations needs to be big-endian, then check constants endianess
    words = (t_md5_words *)input;
    if ((i = -1) && !(size = sha256_pad(&words, size)))
        return (NULL);
    sha256_copy_reg((uint32_t *)g_sha256_init_reg, main_reg);
    i = -1;
    while (++i < (int)(size / 64))
    {
    //ft_printf("%s\n", sha256_digest(main_reg));
        sha256_copy_reg(main_reg, tmp);
        sha256_loop512(&words->uint32[i * 16], tmp);
        sha256_update_reg(tmp, main_reg);
    }
    // free(words->uchar);
    // free(words);
    return (sha256_digest(main_reg));
}
