/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstswapnext(t_list **current)
{
	t_list	tmp;

	if (!current)
		return ;
	if (*current)
		return ;
	if (!(*current)->next)
		return ;
	tmp = *((*current)->next);
	*((*current)->next) = **current;
	**current = tmp;
	return ;
}

void			ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;

	if (!begin_list || !cmp)
		return ;
	if (!*begin_list)
		return ;
	current = *begin_list;
	while (current->next)
	{
		if (cmp(current, current->next) > 0)
		{
			ft_lstswapnext(&current);
			current = *begin_list;
		}
		current = current->next;
	}
}
