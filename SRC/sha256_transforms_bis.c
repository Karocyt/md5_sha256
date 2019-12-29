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

uint32_t	sha256_bsig0(uint32_t b, uint32_t c, uint32_t d)
{
	return (

		(b & c) ^ ((~b) & d));
}

uint32_t	sha256_bsig1(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & c) ^ (b & d) ^ (c & d));
}

uint32_t	sha256_ssig0(uint32_t b, uint32_t c, uint32_t d)
{
	return (

		(b & c) ^ ((~b) & d));
}

uint32_t	sha256_ssig1(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & c) ^ (b & d) ^ (c & d));
}
