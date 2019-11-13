/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_minint_itoa(long long *nb, char *res, int *i)
{
	if (*nb != -2147483648)
		*nb = -(*nb);
	else
	{
		res[*i] = 8 + 48;
		*i += 1;
		*nb = -(*nb / 10);
	}
}

static int		ft_dec_count(long long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(long long nb)
{
	int		i;
	int		neg;
	char	*res;

	neg = 0;
	i = 0;
	if (!(res = ft_memalloc(sizeof(char) * ft_dec_count(nb) + 1)))
		return (NULL);
	if (nb < 0)
	{
		neg = 1;
		ft_minint_itoa(&nb, res, &i);
	}
	while (nb >= 10)
	{
		res[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	res[i] = nb % 10 + 48;
	if (neg)
		res[++i] = '-';
	return (ft_strrev(res));
}
