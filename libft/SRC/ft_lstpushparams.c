/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpushparams.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpushparams(int ac, char **av)
{
	t_list		*begin_list;
	int			i;

	i = 0;
	if (ac < 2)
		return (NULL);
	begin_list = ft_lstnew(av[i], ft_strlen(av[i]));
	while (++i < ac)
		ft_lstappend(&begin_list, ft_lstnew(av[i], ft_strlen(av[i])));
	return (begin_list);
}
