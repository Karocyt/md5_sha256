/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
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

void	ft_putnbr_base(long long nb, int obase)
{
	char base[17];

	ft_memcpy(base, "0123456789ABCDEF", 17);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= obase)
		ft_putnbr_base(nb / obase, obase);
	ft_putchar(base[nb % obase]);
}

void	ft_putnbr_ubase_limit(unsigned long long nb, size_t obase, int limit)
{
	char base[17];

	ft_memcpy(base, "0123456789ABCDEF", 17);
	if (nb >= obase && limit)
		ft_putnbr_ubase_limit(nb / obase, obase, limit - 1);
	ft_putchar(base[nb % obase]);
}
