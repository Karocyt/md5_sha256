/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/06 15:08:57 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *ptr, int size)
{
	int				i;
	unsigned char	tmp;
	unsigned char	*mem;

	mem = (unsigned char *)ptr;
	i = -1;
	while (++i < --size)
	{
		tmp = mem[i];
		mem[i] = mem[size];
		mem[size] = tmp;
	}
	return ;
}
