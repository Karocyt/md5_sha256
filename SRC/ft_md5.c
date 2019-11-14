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

static size_t pad_mod512(unsigned char **input, size_t size)
{
	int 			new_size;
	char 			*tmp;

	new_size = (size / 512 + 1) * 512; // %512 should be 448
	if (new_size - 64 <= size)
		new_size += 512;
	if (!(tmp = ft_memalloc(new_size)))
		return (0);
	ft_memcpy(tmp, *input, size);
	tmp[size] = 1;
	ft_memcpy(tmp + new_size - 64, (unsigned char *)&(uint64_t)size, 8); 
	free(*input);
	*input = tmp;
	return (new_size);
}

char *ft_md5(unsigned char *input, size_t size)
{
	size = pad_mod512(&input, size);
	



	return (ft_strdup("OK\n\n"));
}
