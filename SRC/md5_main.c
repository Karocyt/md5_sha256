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

char *ssl_md5(unsigned char *input, size_t size)
{
	//return (ft_strdup("MD5"));
	//(void)size;
	//(void)input;
    t_md5_words words;

    words = (t_md5_words)input;
	if (!(size = md5_pad(&words, size)))
        return (NULL);
	



	return (ft_strdup("MD5"));
}
