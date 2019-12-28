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

static void ssl_opts_print(char *output, t_params *params)
{
	ft_putendl(output);
	free(output);
	(void)params;
}


static char *apply_hash(t_item *item, char *(*f)(unsigned char*, size_t))
{
	char *res;

	//ft_printf("Apply_hash\n");
	res = f(item->content, item->size);
	return (res);
}

// return 0 success
int ssl_process(t_params *params)
{
	t_item 			*item;
	char 			*(*orig)(unsigned char*, size_t);
	void			*digest;

    //ft_printf("process\n");
	item = params->items;
	while (item)
	{
		if (params->c)
		{
			orig = g_originals[params->h];
			digest = orig(item->content, item->size);
			free(digest);
		}
		ssl_opts_print(apply_hash(item, g_funcs[params->h]), params);
		item = item->next;
	}
	return (0);
}
