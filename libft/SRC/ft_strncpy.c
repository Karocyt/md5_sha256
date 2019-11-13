/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
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

static int	ft_detect_utf8len(unsigned char c)
{
	if (MB_CUR_MAX > 1 && c >= 0x7f && c < 0xC0)
		return (1);
	if (c <= (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		return (1);
	if (c < 224)
		return (2);
	if (c < 240)
		return (3);
	if (c < 248)
		return (4);
	return (0);
}

char		*ft_utf8_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	size_src;

	i = 0;
	size_src = 0;
	while (src[size_src])
		size_src++;
	while (src[i] && i < n)
	{
		if (src[i] && i < size_src
			&& i + ft_detect_utf8len((unsigned char)src[i]) < n)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}

char		*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	size_src;

	i = 0;
	size_src = 0;
	while (src[size_src])
		size_src++;
	while (src[i] && i < n)
	{
		if (src[i] && i < size_src && i < n)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}
