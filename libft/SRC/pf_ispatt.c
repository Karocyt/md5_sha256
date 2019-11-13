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

int	pf_ispatt(t_pattern *patt, char **str, int *i,
				va_list ap)
{
	int	ret;
	int	*lastpos;

	lastpos = &i[1];
	ret = 0;
	ft_apply_fmt(patt, ap);
	*i += patt->len + 1;
	if ((ret = patt->ret) != -1)
	{
		str[1] = ft_str_merge_to_next_patt(&str[1], str[0] + *lastpos);
		ft_append_patt(patt, str, &ret);
		*lastpos = *i;
	}
	ft_free_patt(&patt);
	return (ret);
}
