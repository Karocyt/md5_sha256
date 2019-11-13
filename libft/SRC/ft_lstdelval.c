/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelval.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelval(t_list **begin_list, void *data_ref,
					int (*cmp)())
{
	t_list		*current;
	t_list		*prev;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if (current->content_size && current->content)
			if (!(*cmp)(current->content, data_ref))
			{
				if (current->content)
					free(current->content);
				if (!prev)
					*begin_list = current->next;
				else
					prev->next = current->next;
				free(current);
			}
		prev = current;
		current = current->next;
	}
	return ;
}
