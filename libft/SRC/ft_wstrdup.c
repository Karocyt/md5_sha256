/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrdup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_wstrdup(wchar_t *src)
{
	size_t	size_src;
	wchar_t	*cpy;

	size_src = ft_wstrlen(src);
	if (!(cpy = ft_memalloc(sizeof(*src) * (size_src + 1))))
		return (0);
	return (ft_wstrcpy(cpy, src));
}
