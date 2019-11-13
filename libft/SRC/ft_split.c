/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/04 21:00:32 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_in_chars(char c, char *chars)
{
	int i;

	i = -1;
	while (chars[++i])
		if (chars[i] == c)
			return (1);
	return (0);
}

static size_t	nb_slices(char *str, char *chars)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str && !is_in_chars(*str, chars))
			count++;
		while (*str && !is_in_chars(*str, chars))
			str++;
		while (*str && is_in_chars(*str, chars))
			str++;
	}
	return (count);
}

static size_t	w_len(char *str, char *chars)
{
	size_t	i;

	i = 0;
	while (str[i] && !is_in_chars(str[i], chars))
		i++;
	return (i);
}

char			**ft_split(char *s, char *chars)
{
	char	**tab;
	int		w;

	if (!s)
		return (NULL);
	w = -1;
	if (!(tab = ft_memalloc(sizeof(char *) * (nb_slices(s, chars) + 1))))
		return (NULL);
	while (*s)
	{
		while (is_in_chars(*s, chars))
			s++;
		if (*s)
			if (!(tab[++w] = ft_strndup(s, w_len(s, chars))))
				return (NULL);
		while (*s && !is_in_chars(*s, chars))
			s++;
	}
	if (w == -1)
		ft_memdel((void **)&tab);
	return (tab);
}
