/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **pos, t_list *new)
{
	int		flag;

	flag = 0;
	if (!new)
		return ;
	if (!pos)
		flag = 1;
	else if (!*pos)
		flag = 1;
	if (flag)
	{
		*pos = new;
		return ;
	}
	new->next = *pos;
	*pos = new;
}
