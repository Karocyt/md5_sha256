/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrchr(const wchar_t *s, int c)
{
	wchar_t	stop;
	wchar_t	*str;

	str = (wchar_t *)s;
	stop = (wchar_t)c;
	if (str)
		while (*str)
		{
			if (*str == c)
				return (str);
			str++;
		}
	if (!stop)
		return (str);
	return (NULL);
}
