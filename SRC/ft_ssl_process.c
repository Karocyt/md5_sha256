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
	&ft_md5
};

static t_params *ssl_read_opts(int ac, char *str)
{
	int 	i;
	int 	y;
	int 	index;
	t_uopts	*opts;

	printf("read_opts\n");
	i = 0;
	y = 0;
	if (!(opts = ft_memalloc(sizeof(t_uopts))))
		return (NULL);
	opts->opts.h = MD5;
	while (str && str[0] == '-' && str[1] && str[++i])
	{
		printf("\t reading...\n");
		index = str[i] - 'p';
		if ((index == 3 && ac > 1) || (index != 3 && index >= 0 && index < 4 && !opts->str[index]))
			opts->str[index]++;
		else // if is not a flag, or already set, or string without other arg
			return ((t_params *)ft_free_ret(opts, 0));
	}
	return ((t_params *)opts);
}

static void ssl_opts_print(char *output, t_params *opts)
{
	(void)opts;
	ft_putstr(output);
	free(output);
	free(opts);
}


static char *apply_hash(unsigned char *input, size_t size, char *(*f)(unsigned char*, size_t))
{
	char *res;

	printf("Apply_hash\n");
	res = f(input, size);
	free(input);
	return (res);
}

// return 0 success
int ft_ssl_process(int ac, char **av)
{
	t_params		*opts;
	int				i;
	unsigned char	*input;
	long int		size;
	int				count;

	i = 1;
	count = 0;
	while (++i < ac || (i == ac && !count))
	{
		if (!(opts = ssl_read_opts(ac - i, av[i])))
			return (1);
		i += (*(int *)opts != 0); // move i if there was opts
		if (!count++ && i == ac && !opts->s) // if first pass and no more args and not string, then stdin
			opts->fd = 1;
		else if ((opts->fd = open(av[i], O_RDONLY)) < 0) // else stdout
			return (ft_free_ret(opts, 1));
		if ((size = ft_get_fd_content(&input, opts->fd)) < 0)
			return (ft_free_ret(opts, 1));
		ssl_opts_print(apply_hash(input, size, g_funcs[opts->h]), opts);
	}
	return (0);
}
