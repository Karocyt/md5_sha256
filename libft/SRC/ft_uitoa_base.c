/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: exam <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:22:35 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 11:53:19 by exam        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		dec_count(unsigned long long nb, int base)
{
	int d;

	d = 0;
	if (base < 2 || base > 16)
		return (1);
	while (nb / base)
	{
		d++;
		nb = nb / base;
	}
	d++;
	return (d);
}

char			*ft_uitoa_base(unsigned long long nbr, int base)
{
	char	*res;
	int		i;
	char	obase[17];

	ft_strcpy(obase, "0123456789abcdef");
	i = dec_count(nbr, base);
	if (base < 2 || base > 16 || !i || !nbr)
		return (ft_strdup("0"));
	if (!(res = malloc(sizeof(wchar_t) * (i + 1))))
		return (ft_strdup("0"));
	res[i] = 0;
	while (i && nbr)
	{
		res[--i] = obase[nbr % base];
		nbr = nbr / base;
	}
	if (nbr)
	{
		res[--i] = obase[nbr % base];
		nbr = nbr / base;
	}
	return (res);
}
