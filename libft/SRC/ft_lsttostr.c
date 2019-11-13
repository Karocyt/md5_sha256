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

char	*ft_lsttostr(t_list *current)
{
	size_t	i;
	char	*str;

	if (!current)
		return (ft_strdup(""));
	i = ft_lstsize(current);
	if (!(str = malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = 0;
	i = -1;
	while (current)
	{
		str[++i] = *(char *)(current->content);
		current = current->next;
	}
	return (str);
}

char	*ft_lsttostr_size(t_list *current, size_t size)
{
	size_t	i;
	char	*str;

	if (!current)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	i = -1;
	while (current && ++i < size)
	{
		str[i] = *(char *)(current->content);
		current = current->next;
	}
	str[i] = 0;
	return (str);
}
