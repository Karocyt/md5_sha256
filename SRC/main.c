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

void *g_funcs[NB_ALGOS] =
{
	&ssl_md5,
	&ssl_sha256
};

void *g_originals[NB_ALGOS] =
{
	&md5_original,
	&sha256_original
};

static void	ssl_opts_print(char *output, t_params *params)
{
	if (params->c)
		ft_putstr("ft_ssl:\t\t");
	ft_putendl(output);
	free(output);
	(void)params;
}

static int	ssl_clean(t_params *params, int i)
{
	if (params)
	{
		ssl_clear_items(&params->items);
		free(params);
	}
	return (i);
}

static int	ssl_process(t_params *params)
{
	t_item	*item;
	char	*(*orig)(unsigned char*, size_t);
	char	*(*mine)(unsigned char*, size_t);
	void	*digest;

	item = params->items;
	while (item)
	{
		if (params->c)
		{
			orig = g_originals[params->h];
			digest = orig(item->content, item->size);
			free(digest);
		}
		mine = g_funcs[params->h];
		ssl_opts_print(mine(item->content, item->size), params);
		item = item->next;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_params *params;

	params = NULL;
	if (ac > 1 && (params = ft_memalloc(sizeof(t_params))) &&
		!ssl_read_params(ac, av, params) && !ssl_process(params))
		return (ssl_clean(params, 0));
	ft_putstr(USAGE);
	return (ssl_clean(params, 1));
}
