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
#include <stdlib.h>

wchar_t			*ft_strtowstr(char *src)
{
	size_t	size_src;
	wchar_t	*cpy;
	size_t	i;

	i = -1;
	size_src = ft_strlen(src);
	if (!(cpy = malloc(sizeof(*cpy) * (size_src + 1))))
		return (0);
	cpy[size_src] = 0;
	while (src[++i])
		cpy[i] = src[i];
	free(src);
	return (cpy);
}
