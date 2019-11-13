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

char				*ft_strndup(const char *src, size_t n)
{
	size_t	size_src;
	char	*new;

	size_src = ft_strlen((char *)src);
	if (size_src < n)
		n = size_src;
	if (!(new = malloc(sizeof(*src) * n + 1)))
		return (NULL);
	ft_strncpy(new, (char *)src, n + 1);
	new[n] = 0;
	return (new);
}

char				*ft_utf8_strndup(const char *src, size_t n)
{
	size_t	size_src;
	char	*new;

	size_src = ft_strlen((char *)src);
	if (size_src < n)
		n = size_src;
	if (!(new = malloc(sizeof(*src) * n + 1)))
		return (NULL);
	ft_utf8_strncpy(new, (char *)src, n + 1);
	new[n] = 0;
	return (new);
}
