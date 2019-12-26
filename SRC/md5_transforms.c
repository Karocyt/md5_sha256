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
    AND = &
    OR = |
    NOT = ~
    XOR = ^
    leftrotate = combo << | >> to don't loose anything
    https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm
*/

uint32_t    F(uint32_t B, uint32_t C, uint32_t D)
{
    return ((B & C) | (~B & D));
}

uint32_t    G(uint32_t B, uint32_t C, uint32_t D)
{
    return ((B ^ D ) | (C & ~D));
}

uint32_t    H(uint32_t B, uint32_t C, uint32_t D)
{
    return (B ^ C ^ D);
}

uint32_t    I(uint32_t B, uint32_t C, uint32_t D)
{
    return (C ^ (B | ~D));
}

uint32_t    leftrotate(uint32_t x, uint32_t c)
{
    return ((x << c) | (x >> (sizeof(uint32_t)-c)));
}