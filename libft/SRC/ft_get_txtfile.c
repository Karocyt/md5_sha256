/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 11:15:28 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

char	**ft_get_txtfile(char *filename)
{
	char	**res;
	int		i;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	res = ft_memalloc(sizeof(*res) * (2));
	i = -0;
	while (res && get_next_line(fd, &res[i++]) > 0)
		res = ft_realloc2(res, sizeof(*res) * (i + 1), sizeof(*res) * (i + 2));
	get_next_line(fd, NULL);
	close(fd);
	return (res);
}
