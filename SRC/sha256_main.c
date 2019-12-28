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

/*
	https://tools.ietf.org/html/rfc4634
	http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf
	https://en.wikipedia.org/wiki/SHA-2
*/

char *ssl_sha256(unsigned char *input, size_t size)
{
    return (ft_strdup("SHA256"));
    (void)size;
    (void)input;
    //size = pad_mod512(&input, size);
    



    return (ft_strdup("SHA256"));
}