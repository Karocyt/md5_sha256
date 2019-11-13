/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, size_t size_buff)
{
	size_t	i;
	size_t	j;
	size_t	size_dest;

	j = 0;
	i = ft_strlen(dest);
	size_dest = i;
	while (src[j])
	{
		if (i < size_buff - 1 && size_buff > 1)
			dest[i++] = src[j];
		j++;
	}
	if (i < size_buff)
		dest[i++] = 0;
	return ((i < size_buff) ? size_buff + j : size_dest + j);
}
