/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lsttostr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_strtolst(char *str)
{
	t_list	*list;
	t_list	*new;
	t_list	*last;
	int		i;

	i = -1;
	list = NULL;
	last = NULL;
	while (str[++i])
	{
		new = ft_lstnew(&str[i], 1);
		ft_lstappend(&last, new);
		last = new;
		if (!list)
			list = new;
	}
	return (list);
}
