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

const uint32_t g_add[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
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

void	md5_round1(uint32_t *words, t_reg *r)
{
	r->a = r->b + lr((r->a + F(r->b, r->c, r->d) + words[0] + g_add[0]), 7);
	r->d = r->a + lr((r->d + F(r->a, r->b, r->c) + words[1] + g_add[1]), 12);
	r->c = r->d + lr((r->c + F(r->d, r->a, r->b) + words[2] + g_add[2]), 17);
	r->b = r->c + lr((r->b + F(r->c, r->d, r->a) + words[3] + g_add[3]), 22);
	r->a = r->b + lr((r->a + F(r->b, r->c, r->d) + words[4] + g_add[4]), 7);
	r->d = r->a + lr((r->d + F(r->a, r->b, r->c) + words[5] + g_add[5]), 12);
	r->c = r->d + lr((r->c + F(r->d, r->a, r->b) + words[6] + g_add[6]), 17);
	r->b = r->c + lr((r->b + F(r->c, r->d, r->a) + words[7] + g_add[7]), 22);
	r->a = r->b + lr((r->a + F(r->b, r->c, r->d) + words[8] + g_add[8]), 7);
	r->d = r->a + lr((r->d + F(r->a, r->b, r->c) + words[9] + g_add[9]), 12);
	r->c = r->d + lr((r->c + F(r->d, r->a, r->b) + words[10] + g_add[10]), 17);
	r->b = r->c + lr((r->b + F(r->c, r->d, r->a) + words[11] + g_add[11]), 22);
	r->a = r->b + lr((r->a + F(r->b, r->c, r->d) + words[12] + g_add[12]), 7);
	r->d = r->a + lr((r->d + F(r->a, r->b, r->c) + words[13] + g_add[13]), 12);
	r->c = r->d + lr((r->c + F(r->d, r->a, r->b) + words[14] + g_add[14]), 17);
	r->b = r->c + lr((r->b + F(r->c, r->d, r->a) + words[15] + g_add[15]), 22);
}

void	md5_round2(uint32_t *words, t_reg *r)
{
	r->a = r->b + lr((r->a + G(r->b, r->c, r->d) + words[1] + g_add[16]), 5);
	r->d = r->a + lr((r->d + G(r->a, r->b, r->c) + words[6] + g_add[17]), 9);
	r->c = r->d + lr((r->c + G(r->d, r->a, r->b) + words[11] + g_add[18]), 14);
	r->b = r->c + lr((r->b + G(r->c, r->d, r->a) + words[0] + g_add[19]), 20);
	r->a = r->b + lr((r->a + G(r->b, r->c, r->d) + words[5] + g_add[20]), 5);
	r->d = r->a + lr((r->d + G(r->a, r->b, r->c) + words[10] + g_add[21]), 9);
	r->c = r->d + lr((r->c + G(r->d, r->a, r->b) + words[15] + g_add[22]), 14);
	r->b = r->c + lr((r->b + G(r->c, r->d, r->a) + words[4] + g_add[23]), 20);
	r->a = r->b + lr((r->a + G(r->b, r->c, r->d) + words[9] + g_add[24]), 5);
	r->d = r->a + lr((r->d + G(r->a, r->b, r->c) + words[14] + g_add[25]), 9);
	r->c = r->d + lr((r->c + G(r->d, r->a, r->b) + words[3] + g_add[26]), 14);
	r->b = r->c + lr((r->b + G(r->c, r->d, r->a) + words[8] + g_add[27]), 20);
	r->a = r->b + lr((r->a + G(r->b, r->c, r->d) + words[13] + g_add[28]), 5);
	r->d = r->a + lr((r->d + G(r->a, r->b, r->c) + words[2] + g_add[29]), 9);
	r->c = r->d + lr((r->c + G(r->d, r->a, r->b) + words[7] + g_add[30]), 14);
	r->b = r->c + lr((r->b + G(r->c, r->d, r->a) + words[12] + g_add[31]), 20);
}

void	md5_round3(uint32_t *words, t_reg *r)
{
	r->a = r->b + lr((r->a + H(r->b, r->c, r->d) + words[5] + g_add[32]), 4);
	r->d = r->a + lr((r->d + H(r->a, r->b, r->c) + words[8] + g_add[33]), 11);
	r->c = r->d + lr((r->c + H(r->d, r->a, r->b) + words[11] + g_add[34]), 16);
	r->b = r->c + lr((r->b + H(r->c, r->d, r->a) + words[14] + g_add[35]), 23);
	r->a = r->b + lr((r->a + H(r->b, r->c, r->d) + words[1] + g_add[36]), 4);
	r->d = r->a + lr((r->d + H(r->a, r->b, r->c) + words[4] + g_add[37]), 11);
	r->c = r->d + lr((r->c + H(r->d, r->a, r->b) + words[7] + g_add[38]), 16);
	r->b = r->c + lr((r->b + H(r->c, r->d, r->a) + words[10] + g_add[39]), 23);
	r->a = r->b + lr((r->a + H(r->b, r->c, r->d) + words[13] + g_add[40]), 4);
	r->d = r->a + lr((r->d + H(r->a, r->b, r->c) + words[0] + g_add[41]), 11);
	r->c = r->d + lr((r->c + H(r->d, r->a, r->b) + words[3] + g_add[42]), 16);
	r->b = r->c + lr((r->b + H(r->c, r->d, r->a) + words[6] + g_add[43]), 23);
	r->a = r->b + lr((r->a + H(r->b, r->c, r->d) + words[9] + g_add[44]), 4);
	r->d = r->a + lr((r->d + H(r->a, r->b, r->c) + words[12] + g_add[45]), 11);
	r->c = r->d + lr((r->c + H(r->d, r->a, r->b) + words[15] + g_add[46]), 16);
	r->b = r->c + lr((r->b + H(r->c, r->d, r->a) + words[2] + g_add[47]), 23);
}

void	md5_round4(uint32_t *words, t_reg *r)
{
	r->a = r->b + lr((r->a + I(r->b, r->c, r->d) + words[0] + g_add[48]), 6);
	r->d = r->a + lr((r->d + I(r->a, r->b, r->c) + words[7] + g_add[49]), 10);
	r->c = r->d + lr((r->c + I(r->d, r->a, r->b) + words[14] + g_add[50]), 15);
	r->b = r->c + lr((r->b + I(r->c, r->d, r->a) + words[5] + g_add[51]), 21);
	r->a = r->b + lr((r->a + I(r->b, r->c, r->d) + words[12] + g_add[52]), 6);
	r->d = r->a + lr((r->d + I(r->a, r->b, r->c) + words[3] + g_add[53]), 10);
	r->c = r->d + lr((r->c + I(r->d, r->a, r->b) + words[10] + g_add[54]), 15);
	r->b = r->c + lr((r->b + I(r->c, r->d, r->a) + words[1] + g_add[55]), 21);
	r->a = r->b + lr((r->a + I(r->b, r->c, r->d) + words[8] + g_add[56]), 6);
	r->d = r->a + lr((r->d + I(r->a, r->b, r->c) + words[15] + g_add[57]), 10);
	r->c = r->d + lr((r->c + I(r->d, r->a, r->b) + words[6] + g_add[58]), 15);
	r->b = r->c + lr((r->b + I(r->c, r->d, r->a) + words[13] + g_add[59]), 21);
	r->a = r->b + lr((r->a + I(r->b, r->c, r->d) + words[4] + g_add[60]), 6);
	r->d = r->a + lr((r->d + I(r->a, r->b, r->c) + words[11] + g_add[61]), 10);
	r->c = r->d + lr((r->c + I(r->d, r->a, r->b) + words[2] + g_add[62]), 15);
	r->b = r->c + lr((r->b + I(r->c, r->d, r->a) + words[9] + g_add[63]), 21);
}

void	md5_loop512(uint32_t *words, t_reg *r)
{
	md5_round1(words, r);
	md5_round2(words, r);
	md5_round3(words, r);
	md5_round4(words, r);
}
