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

static size_t pad_mod512_minus64(unsigned char **input, size_t size)
{
	int 			new_size;
	unsigned char	*res;

	new_size = (size / 512 + 1) * 512 - 64; // %512 should be 448
	if (!(res = ft_memalloc(new_size)))
		return (0);

	return (new_size);
}

char *ft_md5(unsigned char *input, size_t size)
{
	(void)size;
	(void)input;
	return (ft_strdup("OK\n\n"));
}
