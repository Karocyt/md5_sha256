/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t				*ft_wstrndup(const wchar_t *src, size_t n)
{
	size_t	size_src;
	wchar_t	*new;

	size_src = ft_wstrlen((wchar_t *)src);
	if (size_src < n)
		n = size_src;
	if (!(new = malloc(sizeof(*src) * (n + 1))))
		return (NULL);
	ft_wstrncpy(new, (wchar_t *)src, n + 1);
	new[n] = 0;
	return (new);
}
