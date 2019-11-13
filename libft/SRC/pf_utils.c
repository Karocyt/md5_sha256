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

void	ft_free_patt(t_pattern **patt)
{
	if ((*patt)->res)
		ft_memdel((void **)&(*patt)->res);
	ft_memdel((void **)patt);
}

int		ft_detect_int_pattern(char *str)
{
	size_t	i;

	i = 0;
	if (*str == '*')
		return (1);
	while (str[i] > 47 && str[i] < 59)
		i++;
	return (i);
}

int		ft_set_flags(t_pattern *patt, char **str)
{
	char	*flags;
	char	*begin;
	int		i;

	i = 0;
	if (!str || !*str)
		return (1);
	while (ft_strchr(PF_FLAGS, (*str)[i]))
		i++;
	flags = ft_strndup(*str, i);
	if (!(begin = flags))
		return (1);
	while (*flags)
	{
		patt->htag_flag = (*flags == '#') ? 1 : patt->htag_flag;
		patt->plus_flag = (*flags == '+') ? 1 : patt->plus_flag;
		patt->minus_flag = (*flags == '-') ? 1 : patt->minus_flag;
		patt->zero_flag = (*flags == '0') ? 1 : patt->zero_flag;
		patt->space_flag = (*flags == ' ') ? 1 : patt->space_flag;
		flags++;
	}
	free(begin);
	*str += i;
	return (1);
}

char	*ft_pad(char *str, size_t minlen, char c, int right_padded)
{
	int		i;
	char	*res;

	if (ft_strlen(str) >= minlen)
		return (str);
	if (!(res = malloc(sizeof(char) * (minlen + 1))))
		return (NULL);
	ft_strset(res, c, minlen);
	res[minlen] = 0;
	i = -1;
	if (right_padded)
		while (str[++i])
			res[i] = str[i];
	else if ((i = ft_strlen(str)))
		while (i-- > 0)
			res[--minlen] = str[i];
	free(str);
	return (res);
}

int		ft_apply_fmt(t_pattern *patt, va_list ap)
{
	if (patt->conv == 'c')
		ft_fmt_c(patt, ap);
	else if (patt->conv == 'B')
		ft_fmt_b(patt, ap);
	else if (!patt->conv || patt->conv == 's' || patt->conv == '%')
		ft_fmt_s(patt, ap);
	else if (ft_strchr("douxXp", patt->conv))
		ft_fmt_d(patt, ap);
	else
		patt->ret = -1;
	return (1);
}
