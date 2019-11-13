/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long long		ft_watoi(wchar_t *str)
{
	short int	s;
	long long	nb;

	nb = 0;
	while (ft_isspace(*str))
		str++;
	s = (*str == '-') ? -1 : 1;
	(*str == '+' || *str == '-') ? str++ : 0;
	while (ft_isdigit(*str))
	{
		if ((*str >= 57 && nb >= 922337203685477580 && s == -1) ||
			(ft_isdigit(*(str + 1)) && nb > 922337203685477580 && s == -1))
			return (0);
		else if ((*str >= 56 && nb >= 922337203685477580 && s == 1) ||
			(ft_isdigit(*(str + 1)) && nb > 922337203685477580 && s == 1))
			return (-1);
		nb = nb * 10 + (*str++ - 48);
	}
	return (nb * s);
}
