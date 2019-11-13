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

char		*ft_str_merge_to_next_patt(char **s1, char *s2)
{
	char	*tmp;
	char	*tmp2;
	char	*next;

	if (!s1)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s2));
	tmp = *s1;
	if (s2)
		*s1 = ft_strcatdup(*s1, s2);
	if ((next = ft_strchr(*s1 + ft_strlen(tmp), '%')))
	{
		tmp2 = *s1;
		*s1 = ft_strndup(*s1, next - *s1);
		free(tmp2);
	}
	if (tmp && s2)
		free(tmp);
	*s1 = ft_str_merge(s1, "");
	return (*s1);
}
