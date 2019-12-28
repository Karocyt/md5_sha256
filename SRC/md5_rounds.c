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

void    md5_round1(uint32_t *words, t_reg *r)
{
    r->a = r->b + ((r->a + F(r->b, r->c, r->d) + words[0] + g_add[1]) << 7);
    r->d = r->a + ((r->d + F(r->a, r->b, r->c) + words[1] + g_add[2]) << 12);
    r->c = r->d + ((r->c + F(r->d, r->a, r->b) + words[2] + g_add[3]) << 17);
    r->b = r->c + ((r->b + F(r->c, r->d, r->a) + words[3] + g_add[4]) << 22);

    r->a = r->b + ((r->a + F(r->b, r->c, r->d) + words[4] + g_add[5]) << 7);
    r->d = r->a + ((r->d + F(r->a, r->b, r->c) + words[5] + g_add[6]) << 12);
    r->c = r->d + ((r->c + F(r->d, r->a, r->b) + words[6] + g_add[7]) << 17);
    r->b = r->c + ((r->b + F(r->c, r->d, r->a) + words[7] + g_add[8]) << 22);
    
    r->a = r->b + ((r->a + F(r->b, r->c, r->d) + words[8] + g_add[9]) << 7);
    r->d = r->a + ((r->d + F(r->a, r->b, r->c) + words[9] + g_add[10]) << 12);
    r->c = r->d + ((r->c + F(r->d, r->a, r->b) + words[10] + g_add[11]) << 17);
    r->b = r->c + ((r->b + F(r->c, r->d, r->a) + words[11] + g_add[12]) << 22);
    
    r->a = r->b + ((r->a + F(r->b, r->c, r->d) + words[12] + g_add[13]) << 7);
    r->d = r->a + ((r->d + F(r->a, r->b, r->c) + words[13] + g_add[14]) << 12);
    r->c = r->d + ((r->c + F(r->d, r->a, r->b) + words[14] + g_add[15]) << 17);
    r->b = r->c + ((r->b + F(r->c, r->d, r->a) + words[15] + g_add[16]) << 22);

}

void    md5_round2(uint32_t *words, t_reg *r)
{
    r->a = r->b + ((r->a + G(r->b, r->c, r->d) + words[1] + g_add[17]) << 5);
    r->d = r->a + ((r->d + G(r->a, r->b, r->c) + words[6] + g_add[18]) << 9);
    r->c = r->d + ((r->c + G(r->d, r->a, r->b) + words[11] + g_add[19]) << 14);
    r->b = r->c + ((r->b + G(r->c, r->d, r->a) + words[0] + g_add[20]) << 20);

    r->a = r->b + ((r->a + G(r->b, r->c, r->d) + words[5] + g_add[21]) << 5);
    r->d = r->a + ((r->d + G(r->a, r->b, r->c) + words[10] + g_add[22]) << 9);
    r->c = r->d + ((r->c + G(r->d, r->a, r->b) + words[15] + g_add[23]) << 14);
    r->b = r->c + ((r->b + G(r->c, r->d, r->a) + words[4] + g_add[24]) << 20);
    
    r->a = r->b + ((r->a + G(r->b, r->c, r->d) + words[9] + g_add[25]) << 5);
    r->d = r->a + ((r->d + G(r->a, r->b, r->c) + words[14] + g_add[26]) << 9);
    r->c = r->d + ((r->c + G(r->d, r->a, r->b) + words[3] + g_add[27]) << 14);
    r->b = r->c + ((r->b + G(r->c, r->d, r->a) + words[8] + g_add[28]) << 20);
    
    r->a = r->b + ((r->a + G(r->b, r->c, r->d) + words[13] + g_add[29]) << 5);
    r->d = r->a + ((r->d + G(r->a, r->b, r->c) + words[2] + g_add[30]) << 9);
    r->c = r->d + ((r->c + G(r->d, r->a, r->b) + words[7] + g_add[31]) << 14);
    r->b = r->c + ((r->b + G(r->c, r->d, r->a) + words[12] + g_add[32]) << 20);
}

void    md5_round3(uint32_t *words, t_reg *r)
{
    r->a = r->b + ((r->a + H(r->b, r->c, r->d) + words[5] + g_add[33]) << 4);
    r->d = r->a + ((r->d + H(r->a, r->b, r->c) + words[8] + g_add[34]) << 11);
    r->c = r->d + ((r->c + H(r->d, r->a, r->b) + words[11] + g_add[35]) << 16);
    r->b = r->c + ((r->b + H(r->c, r->d, r->a) + words[14] + g_add[36]) << 23);

    r->a = r->b + ((r->a + H(r->b, r->c, r->d) + words[1] + g_add[37]) << 4);
    r->d = r->a + ((r->d + H(r->a, r->b, r->c) + words[4] + g_add[38]) << 11);
    r->c = r->d + ((r->c + H(r->d, r->a, r->b) + words[7] + g_add[39]) << 16);
    r->b = r->c + ((r->b + H(r->c, r->d, r->a) + words[10] + g_add[40]) << 23);
    
    r->a = r->b + ((r->a + H(r->b, r->c, r->d) + words[13] + g_add[41]) << 4);
    r->d = r->a + ((r->d + H(r->a, r->b, r->c) + words[0] + g_add[42]) << 11);
    r->c = r->d + ((r->c + H(r->d, r->a, r->b) + words[3] + g_add[43]) << 16);
    r->b = r->c + ((r->b + H(r->c, r->d, r->a) + words[6] + g_add[44]) << 23);
    
    r->a = r->b + ((r->a + H(r->b, r->c, r->d) + words[9] + g_add[45]) << 4);
    r->d = r->a + ((r->d + H(r->a, r->b, r->c) + words[12] + g_add[46]) << 11);
    r->c = r->d + ((r->c + H(r->d, r->a, r->b) + words[15] + g_add[47]) << 16);
    r->b = r->c + ((r->b + H(r->c, r->d, r->a) + words[2] + g_add[48]) << 23);
}

void    md5_round4(uint32_t *words, t_reg *r)
{
    r->a = r->b + ((r->a + I(r->b, r->c, r->d) + words[0] + g_add[1]) << 6);
    r->d = r->a + ((r->d + I(r->a, r->b, r->c) + words[7] + g_add[2]) << 10);
    r->c = r->d + ((r->c + I(r->d, r->a, r->b) + words[14] + g_add[3]) << 15);
    r->b = r->c + ((r->b + I(r->c, r->d, r->a) + words[5] + g_add[4]) << 21);

    r->a = r->b + ((r->a + I(r->b, r->c, r->d) + words[12] + g_add[5]) << 6);
    r->d = r->a + ((r->d + I(r->a, r->b, r->c) + words[3] + g_add[6]) << 10);
    r->c = r->d + ((r->c + I(r->d, r->a, r->b) + words[10] + g_add[7]) << 15);
    r->b = r->c + ((r->b + I(r->c, r->d, r->a) + words[1] + g_add[8]) << 21);
    
    r->a = r->b + ((r->a + I(r->b, r->c, r->d) + words[8] + g_add[9]) << 6);
    r->d = r->a + ((r->d + I(r->a, r->b, r->c) + words[15] + g_add[10]) << 10);
    r->c = r->d + ((r->c + I(r->d, r->a, r->b) + words[6] + g_add[11]) << 15);
    r->b = r->c + ((r->b + I(r->c, r->d, r->a) + words[13] + g_add[12]) << 21);
    
    r->a = r->b + ((r->a + I(r->b, r->c, r->d) + words[4] + g_add[13]) << 6);
    r->d = r->a + ((r->d + I(r->a, r->b, r->c) + words[11] + g_add[14]) << 10);
    r->c = r->d + ((r->c + I(r->d, r->a, r->b) + words[2] + g_add[15]) << 15);
    r->b = r->c + ((r->b + I(r->c, r->d, r->a) + words[9] + g_add[16]) << 21);
}

void    md5_loop512(uint32_t *words, t_reg *r)
{
    md5_round1(words, r);
    md5_round2(words, r);
    md5_round3(words, r);
    md5_round4(words, r);
}