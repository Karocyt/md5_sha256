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
#include <unistd.h>

int			ft_mbslen(char *str)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (str[++i] && !check)
	{
		if (!((str[i] >> 5) ^ 0x6))
			check = 1;
		else if (!((str[i] >> 6) ^ 0xE))
			check = 2;
		else if (!((str[i] >> 5) ^ 0x1E))
			check = 3;
		while (check)
			if (str[++i] && !((str[i] >> 6) ^ 0x2))
				check--;
	}
	return (check ? -1 : i);
}

void		ft_fmt_c(t_pattern *patt, va_list ap)
{
	intmax_t	c;
	int			tmp;

	patt->res = ft_memalloc(5);
	if (!(c = va_arg(ap, intmax_t)))
	{
		patt->char_0 = 1;
		if (patt->min_field)
			patt->min_field -= 1;
	}
	else if ((!patt->l_lmodif && !patt->ll_lmodif)
		|| (c < 255 && MB_CUR_MAX == 1))
		*patt->res = c;
	else if ((tmp = ft_wctomb(patt->res, c)) < 0)
		patt->ret = -1;
	if (patt->min_field > ft_strlen(patt->res) && patt->zero_flag)
		patt->res = ft_pad(patt->res, patt->min_field, '0', 0);
	else if (patt->min_field > ft_strlen(patt->res) && patt->ret != -1)
		patt->res = ft_pad(patt->res, patt->min_field, ' ', patt->minus_flag);
	if (ft_mbslen < 0)
		patt->ret = -1;
	if (patt->ret == -1)
		patt->res = ft_replace_str(patt->res, ft_strdup(""));
}
