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

#include "libft.h"

void	ft_print_grid(char **grid)
{
	int i;

	i = 0;
	while (*grid)
	{
		ft_putnbr(i++);
		ft_putstr(":");
		ft_putstr(*(grid++));
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
