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
#include <fcntl.h>

static int     ssl_read_opts(char *str, t_params *params)
{
    int i;

    i = 0;
    if (str[i] != '-')
        return (0);
    //ft_printf("read_opts: %s\n", str);
    while (str[++i])
    {
        if (str[i] == 'p' && !params->p)
            params->p = 1;
        else if (str[i] == 'q' && !params->q)
            params->q = 1;
        else if (str[i] == 'r' && !params->r)
            params->r = 1;
        else if (str[i] == 's' && !params->s)
            params->s = 1;
        else
            return (0);
    }
    //ft_printf("opts: pqrs = %d%d%d%d\n", params->p, params->q, params->r, params->s);
    return (1);
}

static int ssl_add_file(char *filename, t_params *params)
{
    int             fd;

    //ft_printf("add_file: %s\n", filename);
    if ((fd = open(filename, O_RDONLY)) < 0) // else stdout
        return (0);
    ssl_add_item_from_fd(&params->items, fd);
    return (1);
}

static int ssl_set_algo(char *str, t_params *params)
{
    if (!ft_strcmp(str, "md5"))
        params->h = MD5;
    else if (!ft_strcmp(str, "sha256"))
        params->h = SHA256;
    else
        return (0);
    //ft_printf("set_algo: %s\n", str);
    return (1);
}

int         ssl_read_params(int ac, char **av, t_params *params)
{
    int         i;

    i = 2;
    if (!ssl_set_algo(av[1], params))
        return (1);
    while (i < ac && ssl_read_opts(av[i], params))
        i++;
    if (params->s)
    {
        if (i == ac)
            return (1);
        params->s = 0;
        ssl_add_item_from_str(&params->items, av[i++]);
    }
    while (i < ac)
        if (!ssl_add_file(av[i++], params))
            return (1);
    if (i != ac)
        return (1);
    if (!params->items)
        ssl_add_item_from_fd(&params->items, 0);
    return (0);

}