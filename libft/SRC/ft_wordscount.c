/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wordscount.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:05 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:05 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordscount(char *str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] != 0)
			count++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (count);
}
