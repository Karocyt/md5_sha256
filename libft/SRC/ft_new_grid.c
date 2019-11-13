/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lsttostr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:04 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_new_grid(int lines, int cols, char c)
{
	int		i;
	int		j;
	char	**grid;

	i = -1;
	if (!(grid = malloc(sizeof(*grid) * (lines + 1))))
		return (NULL);
	while (++i < lines)
	{
		if (!(grid[i] = malloc(cols + 1)))
		{
			ft_free_grid(&grid);
			return (NULL);
		}
		j = -1;
		while (++j < cols)
			grid[i][j] = c;
		grid[i][j] = 0;
	}
	grid[i] = NULL;
	return (grid);
}
