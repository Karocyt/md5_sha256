/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *src, t_list *(*f)(t_list *))
{
	t_list	*new_list;
	t_list	*dst;

	if (!f || !src)
		return (NULL);
	new_list = NULL;
	dst = f(src);
	if (src)
		src = src->next;
	if (dst)
		new_list = dst;
	while (src)
	{
		dst->next = f(src);
		dst = dst->next;
		src = src->next;
	}
	return (new_list);
}
