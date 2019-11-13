/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstiterif.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiterif(t_list *begin_list, void (*f)(void *),
							void *data_ref, int (*cmp)())
{
	t_list		*current;
	size_t		i;

	i = 0;
	current = begin_list;
	while (current)
	{
		if (current->content_size && current->content)
			if (!cmp(current->content, data_ref))
				f(current->content);
		current = current->next;
		i++;
	}
}
