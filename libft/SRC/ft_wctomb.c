/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			ft_wclen(wchar_t c)
{
	int ret;

	ret = 0;
	if (c >= 0xD800 && c <= 0xDFFF)
		return (0);
	else if ((c >= 0 && c <= 0x7F) || (c > 192 && c < 255))
		return (1);
	else if (c > 0x7F && c <= 0x7FF)
		return (2);
	else if (c > 0x7FF && c <= 0xFFFF)
		return (3);
	else if (c > 0xFFFF && c <= 0x10FFFF)
		return (4);
	return (ret);
}

static int	ft_build_utf8(wchar_t c, char *mbs)
{
	int ret;

	ret = -1;
	if (c <= (MB_CUR_MAX == 1 ? 0xFF : 0x7F) && (ret = 1))
		mbs[0] = c;
	else if (c > 0x7F && c <= 0x7FF && (ret = 2))
	{
		mbs[0] = 0xC0 | c >> 6;
		mbs[1] = 0x80 | (c & 0x3F);
	}
	else if (c > 0x7FF && c <= 0xFFFF && (ret = 3))
	{
		mbs[0] = 0xE0 | (c >> 12);
		mbs[1] = 0x80 | ((c >> 6) & 0x3F);
		mbs[2] = 0x80 | (c & 0x3F);
	}
	else if (c > 0xFFFF && c <= 0x10FFFF && (ret = 4))
	{
		mbs[0] = 0xF0 | (c >> 18);
		mbs[1] = 0x80 | ((c >> 12) & 0x3F);
		mbs[2] = 0x80 | ((c >> 6) & 0x3F);
		mbs[3] = 0x80 | (c & 0x3F);
	}
	return (ret);
}

int			ft_wctomb(char *mbs, wchar_t c)
{
	if (!mbs)
		return (-1);
	if (((c >= 0 && c < 128) || (c >= 192 && c < 255)
		|| (c > 0x7F && c <= 0x7FF && MB_CUR_MAX >= 2)
		|| (c > 0x7FF && c <= 0xFFFF && MB_CUR_MAX >= 3)
		|| (c > 0xFFFF && c <= 0x10FFFF && MB_CUR_MAX >= 4))
		&& !(c >= 0xD800 && c <= 0xDFFF))
		return (ft_build_utf8(c, mbs));
	else
	{
		mbs[0] = -1;
		return (-1);
	}
}

int			ft_wcstombs(char **res, wchar_t *wcs)
{
	int		i;
	char	*tmp;
	int		ret;

	if (!wcs)
		return (-1);
	*res = ft_strdup("");
	i = -1;
	ret = 1;
	while (wcs[++i] && ret != -1)
	{
		tmp = ft_memalloc(5);
		ft_wctomb(tmp, wcs[i]);
		if ((wcs[i] >= 0xD800 && wcs[i] <= 0xDFFF) || wcs[i] < 0
			|| wcs[i] == 255 || wcs[i] == 256 || wcs[i] > 0x10FFFF
			|| (wcs[i] >= 256 && MB_CUR_MAX == 1))
			ret = -1;
		ret = ret >= 0 ? ft_wclen(wcs[i]) : ret;
		*res = ret >= 0 ? ft_replace_str(*res, ft_strcatdup(*res, tmp)) : *res;
		free(tmp);
	}
	return (ret);
}

/*
** start: 			2047					4242
** binary:			00000111 11111111		00010000 10010010
**
** (c >> 6:			00000111 11111111		00000000 01000010 -> again
**					00000000 00011111		00000000 00000001
**							 00011111
** | mask 192:				 11010000
** = mbs[0]):				 11011111
**
**
** (binary:			00000111 11111111
** & mask 63):				 11000000
** = tmp:					 11111111
** | mask	128:			 10000000
** mbs[1] =:				 01111111
** mask:			110xxxxx 10xxxxxx
*/
