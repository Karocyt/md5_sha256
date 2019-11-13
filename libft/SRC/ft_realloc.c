/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_realloc2(void *old, size_t old_size, size_t new_size)
{
	void	*new;
	size_t	cpy_size;

	if (!(new = ft_memalloc(new_size)))
		return (NULL);
	cpy_size = (old_size < new_size) ? old_size : new_size;
	if (old && cpy_size)
		ft_memcpy(new, old, cpy_size);
	if (old)
		free(old);
	return (new);
}
