/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/29 10:10:19 by kevazoul    ###    #+. /#+    ###.fr     */
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

uint32_t	sha256_bsig0(uint32_t x)
{
	return (rr(x, 2) ^ rr(x, 13) ^ rr(x, 22));
}

uint32_t	sha256_bsig1(uint32_t x)
{
	return (rr(x, 6) ^ rr(x, 11) ^ rr(x, 25));
}

uint32_t	sha256_ssig0(uint32_t x)
{
	return (rr(x, 7) ^ rr(x, 18) ^ (x >> 3));
}

uint32_t	sha256_ssig1(uint32_t x)
{
	return (rr(x, 17) ^ rr(x, 19) ^ (x >> 10));
}
