/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **begin_list)
{
	t_list		*current;
	t_list		*next;
	t_list		*previous;

	previous = NULL;
	if (!begin_list)
		return ;
	if (*begin_list == NULL)
		return ;
	current = *begin_list;
	while ((*current).next)
	{
		if ((*current).next)
			next = (*current).next;
		(*current).next = previous;
		previous = current;
		if ((*current).next)
			current = next;
		else
			current = *begin_list;
	}
}
