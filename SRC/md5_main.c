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
    https://en.wikipedia.org/wiki/MD5
    http://practicalcryptography.com/hashes/md5-hash/
*/

const uint32_t  g_add[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                            0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                            0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                            0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                            0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                            0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
                            0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                            0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                            0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                            0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                            0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
                            0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                            0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                            0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                            0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                            0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
const t_reg  g_init_reg = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
const uint32_t  g_shift[64] = {7, 12, 17, 22, 7, 12, 17, 22,
                                7, 12, 17, 22, 7, 12, 17, 22,
                                5, 9, 14, 20, 5, 9, 14, 20,
                                5, 9, 14, 20, 5, 9, 14, 20,
                                4, 11, 16, 23, 4, 11, 16, 23,
                                4, 11, 16, 23, 4, 11, 16, 23,
                                6, 10, 15, 21, 6, 10, 15, 21,
                                6, 10, 15, 21, 6, 10, 15, 21};

int    md5_loop64(int i, int *f, uint32_t *words) // returns g
{
    int g;

    if (i < 16)
    {
        *f = F(words[1], words[2], words[3]);
        g = i;
    }
    else if (i < 32)
    {
        *f = G(words[1], words[2], words[3]);
        g = (5 * i + 1) % 16; 
    }
    else if (i < 48)
    {
        *f = H(words[1], words[2], words[3]);
        g = (3 * i + 5) % 16;
    }
    else
    {
        *f = I(words[1], words[2], words[3]);
        g = (7 * i) % 16;
    }
    return (g);
}

void    md5_loop512_old(uint32_t *words, t_reg *r)
{
    int i;
    int f;
    int g;

    i = -1;
    while (++i < 64)
    {
        g = md5_loop64(i, &f, words);
        f = f + r->a + g_add[i] + words[g];
        r->a = r->d;
        r->d = r->c;
        r->c = r->b;
        r->b = r->b + leftrotate(f, g_shift[i]);
        //ft_printf("\ttmp state: %x, %x, %x, %x\n", r->a, r->b, r->c, r->d);
    }
}

void    md5_loop512_reg(uint32_t *words, t_reg *r)
{
    int i;
    int f;
    int g;

    i = -1;
    while (++i < 64)
    {
        g = md5_loop64(i, &f, (uint32_t *)r);
        f = f + r->a + g_add[i] + words[g];
        r->a = r->d;
        r->d = r->c;
        r->c = r->b;
        r->b = r->b + leftrotate(f, g_shift[i]);
        //ft_printf("\ttmp state: %x, %x, %x, %x\n", r->a, r->b, r->c, r->d);
    }
}

char    *md5_digest(t_reg r)
{
    char *res;
    const char  *base = "0123456789abcdef";
    int i;
    uint8_t *uchar;

    if (!(res = malloc(33)))
        return (NULL);
    i = -1;
    uchar = (uint8_t *)&r;
    while (++i < 16)
    {
        res[i * 2] = base[uchar[i] / 16];           //|
        res[i * 2 + 1] = base[uchar[i] % 16];       //| === sprintf(res[i*2], "%02x", uchar[i])
    }
    res[32] = 0;
    return res;
}

char    *ssl_md5(unsigned char *input, size_t size)
{
    t_md5_words *words;
    t_reg       tmp;
    int iter;
    int i;
    t_reg  main_reg;

    // ORIGINAL
    t_reg *original = (t_reg *)md5_original(input, size);
    

    // NEW (as spec)
    words = (t_md5_words *)input;
	if (!(size = md5_pad(&words, size)) )
        return (NULL);
	iter = size / 64;
    i = -1;
    main_reg = g_init_reg;
    while (++i < iter)
    {
        tmp = main_reg;
        md5_loop512(&words->uint32[i * 16], &tmp);
        main_reg.a += tmp.a;
        main_reg.b += tmp.b;
        main_reg.c += tmp.c;
        main_reg.d += tmp.d;
    }
    ft_printf("new_digest: \t%s\n", md5_digest(main_reg));
    if (!ft_memcmp(&main_reg, original, 16))
        ft_printf("SUCCESS!\n");

    // OLD broken (using words instead of registers)
    // words = (t_md5_words *)input;
    // if (!(size = md5_pad(&words, size)) )
    //     return (NULL);
    // iter = size / 64;
    // i = -1;
    // main_reg = g_init_reg;
    // while (++i < iter)
    // {
    //     tmp = main_reg;
    //     md5_loop512_old(&words->uint32[i * 16], &tmp);
    //     main_reg.a += tmp.a;
    //     main_reg.b += tmp.b;
    //     main_reg.c += tmp.c;
    //     main_reg.d += tmp.d;
    // }
    // ft_printf("loop512_old: \t%s\n", md5_digest(main_reg));
    // if (!ft_memcmp(&main_reg, original, 16))
    //     ft_printf("SUCCESS!\n");
    
    // OLD with registers
    words = (t_md5_words *)input;
    if (!(size = md5_pad(&words, size)) )
        return (NULL);
    iter = size / 64;
    i = -1;
    main_reg = g_init_reg;
    while (++i < iter)
    {
        tmp = main_reg;
        md5_loop512_reg(&words->uint32[i * 16], &tmp);
        main_reg.a += tmp.a;
        main_reg.b += tmp.b;
        main_reg.c += tmp.c;
        main_reg.d += tmp.d;
    }
    ft_printf("loop512_reg: \t%s\n", md5_digest(main_reg));
    if (!ft_memcmp(&main_reg, original, 16))
        ft_printf("SUCCESS!\n");

    return (ft_strdup("MD5"));
}
