/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstappend.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstappend(t_list **list, t_list *new)
{
	t_list	*current;

	if (new)
	{
		current = *list;
		if (current)
		{
			while (current->next)
				current = current->next;
			current->next = new;
			current->content_size = 1;
		}
		else
			*list = new;
	}
}
