/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_merge(char **s1, char *s2)
{
	char	*tmp;
	int		i;

	if (!s1)
		return (NULL);
	if (!*s1)
		return (NULL);
	if (!s2)
		return (*s1);
	i = ft_strlen(*s1) + ft_strlen(s2) + 1;
	tmp = malloc(sizeof(*tmp) * i);
	ft_strcpy(tmp, *s1);
	ft_strcat(tmp, s2);
	*s1 = ft_replace_str(*s1, tmp);
	return (*s1);
}
