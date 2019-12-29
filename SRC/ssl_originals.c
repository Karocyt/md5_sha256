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

#if defined(__APPLE__)
# define COMMON_DIGEST_FOR_OPENSSL
# include <CommonCrypto/CommonDigest.h>
# define MD5state_st CC_MD5state_st
# define MD5_ CC_MD5_
#else
# include <openssl/md5.h>
#endif
#include "libft.h"

unsigned char	*md5_original(void *data, size_t len)
{
	unsigned char		*digest;
	struct MD5state_st	context;
	int					i;

	if (!(digest = malloc(16)))
		return (NULL);
	MD5_Init(&context);
	MD5_Update(&context, data, len);
	MD5_Final(digest, &context);
	i = -1;
	ft_printf("md5_original: \t");
	while (++i < 16)
		ft_printf("%02x", (unsigned int)digest[i]);
	ft_printf("\n");
	return (digest);
}

unsigned char	*sha256_original(void *data, size_t len)
{
	(void)data;
	(void)len;
	return (NULL);
}
