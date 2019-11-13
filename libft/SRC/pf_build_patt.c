/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lsttostr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_lmodif(t_pattern *patt, char *lmodifs)
{
	char *backup;

	backup = lmodifs;
	if (!lmodifs)
		return ;
	lmodifs--;
	while (*(++lmodifs))
	{
		if (*lmodifs == 'j')
			patt->j_lmodif = 1;
		else if (*lmodifs == 'z')
			patt->z_lmodif = 1;
		else if (*lmodifs == 'l')
			(*(lmodifs + 1) == 'l') ? (patt->ll_lmodif =
				(*(++lmodifs) == 'l')) : (patt->l_lmodif = 1);
		else if (*lmodifs == 'h')
			(*(lmodifs + 1) == 'h') ? (patt->hh_lmodif =
				(*(++lmodifs) == 'h')) : (patt->h_lmodif = 1);
	}
	free(backup);
}

static void	ft_set_implicitflags(t_pattern *patt)
{
	if (patt->min_field < 0)
	{
		patt->min_field = -patt->min_field;
		patt->minus_flag = 1;
	}
	if (ft_strchr("DOUSC", patt->conv))
	{
		patt->conv = ft_tolower(patt->conv);
		patt->l_lmodif = 1;
	}
	else if (patt->conv == 'p')
	{
		patt->htag_flag = 1;
		patt->l_lmodif = 1;
	}
	else if (patt->conv == 'i')
		patt->conv = 'd';
	if (ft_strchr("pdiouxX", patt->conv)
		&& (patt->precision || patt->precision_0))
		patt->zero_flag = 0;
	return ;
}

static int	ft_set_min_field_n_flags(t_pattern *patt, char **str, va_list ap)
{
	ft_set_flags(patt, str);
	**str == '*' ? patt->min_field = va_arg(ap, int)
		: (patt->min_field = ft_atoi(*str));
	if (patt->min_field > 0x7F)
	{
		patt->min_field = -patt->min_field;
		patt->minus_flag = 1;
	}
	*str += ft_detect_int_pattern(*str);
	ft_set_flags(patt, str);
	return (1);
}

static int	ft_set_flags_n_lmodif(t_pattern *patt, char **str)
{
	int				i;

	i = 0;
	ft_set_flags(patt, str);
	while (ft_strchr(PF_LMODIF, (*str)[i]))
		i++;
	ft_set_lmodif(patt, ft_strndup(*str, i));
	*str += i;
	ft_set_flags(patt, str);
	return (1);
}

t_pattern	*ft_b(char *str, va_list ap)
{
	t_pattern		*patt;
	char			*begin;

	patt = NULL;
	begin = str;
	if (str && (patt = ft_memalloc(sizeof(*patt))) && ft_strlen(str))
	{
		ft_set_min_field_n_flags(patt, &str, ap);
		while (*str == '.')
		{
			if (*++str == '*' && !(patt->precision = va_arg(ap, int)))
				patt->precision_0 = 1;
			else if (!(patt->precision = ft_atoi(str)))
				patt->precision_0 = 1;
			if ((str += ft_detect_int_pattern(str)) && patt->precision > 0x7F)
				patt->precision = 0;
		}
		ft_set_flags_n_lmodif(patt, &str);
		if (ft_strchr(PF_CONV, *str) && (patt->conv = *(str++)))
			patt->len = str - begin;
		patt->len = str - begin - 1;
		ft_set_implicitflags(patt);
	}
	return (patt);
}
