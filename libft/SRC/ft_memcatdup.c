/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:43:46 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:43:54 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_memcatdup(char *s1, char *s2, int size1, int size2)
{
	char	*new_str;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(new_str = ft_memalloc(size1 + size2)))
		return (NULL);
	ft_memcpy(new_str, s1, size1);
	ft_memcpy(new_str + size1, s2, size2);
	return (new_str);
}
