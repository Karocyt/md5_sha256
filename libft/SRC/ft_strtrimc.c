/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrimc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrimlen(char *str, char c)
{
	size_t	trimlen;

	trimlen = 0;
	if (str == NULL || *str == 0)
		return (0);
	while (*str == c)
		str++;
	while (str[trimlen])
		trimlen++;
	while (trimlen && str[trimlen - 1] == c)
		trimlen--;
	return (trimlen);
}

char			*ft_strtrimc(char const *s, char c)
{
	char	*str;
	char	*trim;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	if (!(trim = ft_memalloc(sizeof(*str) * ft_strtrimlen(str, c) + 1)))
		return (NULL);
	while (*str == c)
		str++;
	ft_strncpy(trim, str, ft_strtrimlen(str, c));
	return (trim);
}
