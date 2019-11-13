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

/*
** str[0] = input, str[1] = res
** tab : i; lastpos; patt_size;
*/

int			ft_main_printf(char **res, const char *input, va_list ap)
{
	char		*str[2];
	int			tab[3];
	t_pattern	*patt;
	int			ret;

	ret = 0;
	tab[0] = 0;
	tab[1] = 0;
	str[0] = (char *)input;
	str[1] = ft_strdup("");
	while (tab[0] < (int)ft_strlen(str[0]) && ret != -1)
		if ((str[0][(tab[0])++] == '%') && (patt = ft_b(str[0] + tab[0], ap))
			&& (tab[2] = pf_ispatt(patt, &str[0], tab, ap)) != -42)
			ret = (tab[2] < 0) ? tab[2] : ret + tab[2];
	if (ret != -1 && tab[1] < (int)ft_strlen(str[0]))
		str[1] = ft_str_merge(&str[1], str[0] + tab[1]);
	ret = ret != -1 ? ret + ft_strlen(str[1]) : ret;
	*res = str[1];
	return (ret);
}
