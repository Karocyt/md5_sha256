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

void		ft_append_patt(t_pattern *patt, char **str, int *ret)
{
	if (!patt->minus_flag)
		str[1] = ft_str_merge(&str[1], patt->res);
	if (patt->char_0)
	{
		ft_putstr(str[1]);
		*ret += ft_strlen(str[1]) + 1;
		str[1] = ft_replace_str(str[1], ft_strdup(""));
		write(1, "\0", 1);
	}
	if (patt->minus_flag)
		str[1] = ft_str_merge(&str[1], patt->res);
}
