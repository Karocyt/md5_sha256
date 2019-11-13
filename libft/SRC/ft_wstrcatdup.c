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

wchar_t		*ft_wstrcatdup(wchar_t *s1, wchar_t *s2)
{
	wchar_t	*new;

	if (!s1 && !s2)
		return (ft_strtowstr(""));
	if (!s1)
		return (ft_wstrdup(s2));
	if (!s2)
		return (ft_wstrdup(s1));
	if (!(new = malloc(sizeof(*s1) * (ft_wstrlen(s1) + ft_wstrlen(s2) + 1))))
		return (NULL);
	ft_wstrcpy(new, s1);
	ft_wstrcat(new, s2);
	return (new);
}
