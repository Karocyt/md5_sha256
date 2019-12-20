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

void *g_funcs[1] =
{
	&ssl_md5
};

static void ssl_opts_print(char *output, t_params *opts)
{
	(void)opts;
	ft_putstr(output);
	free(output);
	free(opts);
}


static char *apply_hash(t_item *item, char *(*f)(unsigned char*, size_t))
{
	char *res;

	ft_printf("Apply_hash\n");
	res = f(item->content, item->size);
	return (res);
}

// return 0 success
int ssl_process(t_params *params)
{
	t_item 			*item;

	item = params->items;
	while (item)
	{
		ssl_opts_print(apply_hash(item, g_funcs[params->h]), params);
		item = item->next;
	}
	return (0);
}
