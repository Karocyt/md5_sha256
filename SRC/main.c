/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/03 16:03:21 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

int ssl_clean(t_params *params, int i)
{
    if (params)
    {
        ssl_clear_items(&params->items);
        free(params);
    }
    return (i);
}

int main(int ac, char **av)
{
    t_params *params;

    params = NULL;
    if (ac > 1 && (params = ft_memalloc(sizeof(t_params))) &&
        !ssl_read_params(ac, av, params) && !ssl_process(params))
    {
        //ft_printf("Done.\n");
	   	return (ssl_clean(params, 0));
    }
	//left to clean
    ft_putstr(USAGE);
	return (ssl_clean(params, 1));
}
