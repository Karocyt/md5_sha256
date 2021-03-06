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
**	AND = &
**	OR = |
**	NOT = ~
**	XOR = ^
**	leftrotate = combo << | >> to don't loose anything
**	https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm
*/

uint32_t	sha256_ch(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & c) ^ ((~b) & d));
}

uint32_t	sha256_maj(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & c) ^ (b & d) ^ (c & d));
}

uint32_t	swap_endianess(uint32_t x)
{
	uint32_t	y;
	uint8_t		*strx;
	uint8_t		*stry;
	int			i;

	strx = (uint8_t *)&x;
	stry = (uint8_t *)&y;
	i = -1;
	while (++i < 4)
		stry[i] = strx[3 - i];
	return (y);
}

uint64_t	swap_endianess64(uint64_t x)
{
	uint64_t	y;
	uint8_t		*strx;
	uint8_t		*stry;
	int			i;

	strx = (uint8_t *)&x;
	stry = (uint8_t *)&y;
	i = -1;
	while (++i < 8)
		stry[i] = strx[7 - i];
	return (y);
}

uint32_t	rr(uint32_t x, uint32_t c)
{
	return (((x >> c) | (x << (32 - c))));
}
