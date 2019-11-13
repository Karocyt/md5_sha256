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

static void		ft_get_numvalu(t_pattern *patt, va_list ap)
{
	uintmax_t		u;

	if (!(u = 0) && patt->j_lmodif)
		u = va_arg(ap, uintmax_t);
	else if (patt->z_lmodif)
		u = va_arg(ap, size_t);
	else if (patt->ll_lmodif)
		u = va_arg(ap, unsigned long long);
	else if (patt->l_lmodif)
		u = va_arg(ap, unsigned long);
	else if (patt->h_lmodif)
		u = (unsigned short)va_arg(ap, unsigned int);
	else if (patt->hh_lmodif)
		u = (unsigned char)va_arg(ap, unsigned int);
	else
		u = va_arg(ap, unsigned int);
	patt->null = (!u && patt->conv != 'p') ? 1 : 0;
	if (!u && patt->precision_0)
		patt->res = ft_strdup("");
	else if (patt->conv == 'o')
		patt->res = ft_uitoa_base(u, 8);
	else if (patt->conv == 'x' || patt->conv == 'X' || patt->conv == 'p')
		patt->res = ft_uitoa_base(u, 16);
	else
		patt->res = ft_uitoa_base(u, 10);
}

static void		ft_get_numvali(t_pattern *patt, va_list ap)
{
	intmax_t			i;

	if (!(i = 0) && patt->j_lmodif)
		i = va_arg(ap, intmax_t);
	else if (patt->z_lmodif)
		i = va_arg(ap, ssize_t);
	else if (patt->ll_lmodif)
		i = va_arg(ap, long long);
	else if (patt->l_lmodif)
		i = va_arg(ap, long);
	else if (patt->h_lmodif)
		i = (short)va_arg(ap, int);
	else if (patt->hh_lmodif)
		i = (char)va_arg(ap, int);
	else
		i = va_arg(ap, int);
	patt->null = i ? 0 : 1;
	if (!i && patt->precision_0)
		patt->res = ft_strdup("");
	else
		patt->res = ft_itoa_base(i, 10);
	if (*patt->res == '-' && (patt->neg = 1))
		ft_strpop(&patt->res);
}

static void		ft_append_hex(t_pattern *patt)
{
	if ((patt->conv == 'x' || patt->conv == 'X' || patt->conv == 'p')
		&& patt->htag_flag && !patt->null)
	{
		ft_prepend_char(&(patt->res), 'x');
		ft_prepend_char(&(patt->res), '0');
	}
	if (patt->conv == 'X')
	{
		ft_strtoupper(patt->res);
		patt->res[1] = 'x';
	}
}

static void		ft_apply_numval_flags(t_pattern *patt)
{
	patt->res = ft_pad(patt->res, patt->precision, '0', 0);
	if ((patt->htag_flag
		&& (patt->conv == 'o' || patt->conv == 'x' || patt->conv == 'X'))
		&& (!((patt->precision_0 || patt->htag_flag) && (patt->conv == 'x'
			|| patt->conv == 'X')) && *patt->res != '0'))
		ft_prepend_char(&(patt->res), '0');
	ft_append_hex(patt);
	if (patt->precision > 0)
		patt->res = ft_pad(patt->res, patt->precision, '0', 0);
	if (patt->plus_flag && (patt->conv == 'd') && !patt->neg)
		ft_prepend_char(&(patt->res), '+');
	else if (patt->space_flag && (patt->conv == 'd') && !patt->neg)
		ft_prepend_char(&(patt->res), ' ');
	if (patt->neg)
		ft_prepend_char(&(patt->res), '-');
	if (patt->minus_flag)
		patt->res = ft_pad(patt->res, patt->min_field, ' ', 1);
	else if (!patt->zero_flag)
		patt->res = ft_pad(patt->res, patt->min_field, ' ', 0);
}

void			ft_fmt_d(t_pattern *patt, va_list ap)
{
	int zero_pad;

	if (patt->conv == 'd')
		ft_get_numvali(patt, ap);
	else
		ft_get_numvalu(patt, ap);
	if (patt->zero_flag && !patt->minus_flag)
	{
		zero_pad = patt->min_field;
		if (patt->neg || patt->plus_flag || patt->space_flag)
			zero_pad--;
		if ((patt->conv == 'x' || patt->conv == 'X' || patt->conv == 'p')
			&& patt->htag_flag && (!patt->null))
			zero_pad -= 2;
		patt->res = ft_pad(patt->res, zero_pad > 0 ? zero_pad : 0, '0', 0);
	}
	ft_apply_numval_flags(patt);
	if (!patt->res)
		patt->res = ft_strdup("ERROR");
}
