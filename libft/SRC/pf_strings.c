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

static void		ft_get_s(t_pattern *patt, va_list ap)
{
	char	*tmp;
	wchar_t	*wtmp;
	int		ret;
	int		flag;

	flag = 0;
	if (!patt->conv)
	{
		patt->min_field = (patt->min_field ? patt->min_field - 1 : 0);
		patt->res = ft_strdup("");
	}
	else if (patt->conv == '%')
		patt->res = ft_strdup("%");
	else if (patt->l_lmodif && patt->conv != '%' && (flag = 1)
		&& (wtmp = va_arg(ap, wchar_t *)))
	{
		ret = ft_wcstombs(&patt->res, wtmp);
		patt->ret = ret < 0 ? -1 : 0;
	}
	else if (!flag && patt->conv != '%' && (tmp = va_arg(ap, char *)))
		patt->res = ft_strdup(tmp);
	else if (patt->conv != '%')
		patt->res = ft_strdup("(null)");
	else
		patt->ret = -1;
}

void			ft_fmt_s(t_pattern *patt, va_list ap)
{
	ft_get_s(patt, ap);
	if (patt->precision || (patt->precision_0 && patt->conv != '%'))
	{
		if (MB_CUR_MAX >= 1 && patt->l_lmodif)
			patt->res = ft_replace_str(patt->res,
			ft_utf8_strndup(patt->res, patt->precision));
		else
			patt->res = ft_replace_str(patt->res,
			ft_strndup(patt->res, patt->precision));
	}
	if (patt->min_field > ft_strlen(patt->res)
		&& patt->zero_flag && !patt->minus_flag)
		patt->res = ft_pad(patt->res, patt->min_field, '0', 0);
	else if (patt->min_field > ft_strlen(patt->res))
		patt->res = ft_pad(patt->res, patt->min_field, ' ', patt->minus_flag);
}
