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

static int		ssl_read_opts(char *str, t_params *params)
{
	int i;

	i = 0;
	if (str[i] != '-')
		return (0);
	while (str[++i])
		if (!ft_strchr("pqrsc", str[i]))
			return 0;
	i = 0;
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
		else if (str[i] == 'c' && !params->c)
			params->c = 1;
		else
			return (0);
	}
	return (1);
}

static int		ssl_add_file(char *filename, t_params *params)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	ssl_add_item_from_fd(&params->items, fd, filename);
	return (1);
}

static int		ssl_set_algo(char *str, t_params *params)
{
	if (!ft_strcmp(str, "md5"))
		params->h = MD5;
	else if (!ft_strcmp(str, "sha256"))
		params->h = SHA256;
	else
		return (0);
	params->algo = str;
	return (1);
}

static int		ssl_read_stdin(t_params *params)
{
	int tmp;

	if ((tmp = (uint64_t)ft_get_fd_content((uint8_t **)&params->stdin, 0)) < 0)
		return (0);
	params->stdin_size = (size_t)tmp;
	if (params->items)
		params->stdin_free = 1;
	return (tmp);
}

int				ssl_read_params(int ac, char **av, t_params *p)
{
	int i;

	if ((i = 2) && !ssl_set_algo(av[1], p))
		return (1);
	while (i < ac && ssl_read_opts(av[i], p))
		i++;
	if (p->s)
	{
		if (i == ac)
			return (1);
		p->s = 0;
		ssl_add_item_from_str(&p->items, av[i++]);
	}
	while (i < ac)
		if (!ssl_add_file(av[i++], p))
			return (1);
	if (i != ac)
		return (1);
	if (!p->items || p->p)
		if (ssl_read_stdin(p) < 0)
			return (1);
	if (!p->items)
		if (ssl_add_stdin(&p->items, p->stdin_size, p->stdin) < 0)
			return (1);
	return (0);
}
