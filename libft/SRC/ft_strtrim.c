/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrimlen(char *str)
{
	size_t	trimlen;

	trimlen = 0;
	if (str == NULL || *str == 0)
		return (0);
	while (ft_isspace(*str))
		str++;
	while (str[trimlen])
		trimlen++;
	while (trimlen && ft_isspace(str[trimlen - 1]))
		trimlen--;
	return (trimlen);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	char	*trim;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	if (!(trim = ft_memalloc(sizeof(*str) * ft_strtrimlen(str) + 1)))
		return (NULL);
	while (ft_isspace(*str))
		str++;
	ft_strncpy(trim, str, ft_strtrimlen(str));
	return (trim);
}
