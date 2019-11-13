/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_indexof.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_indexof(int needle, int *haystack, size_t haystack_size)
{
	size_t	i;

	i = 0;
	while (i < haystack_size && haystack)
	{
		if (needle == haystack[i])
			return (i);
		i++;
	}
	return (-1);
}
