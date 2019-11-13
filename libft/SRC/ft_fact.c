/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fact.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_fact(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb == 0)
		return (1);
	if (nb > 12 || nb < 1)
		return (0);
	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
	}
	return (factorial);
}
