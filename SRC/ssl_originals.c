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
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define MD5Context CC_MD5state_st
#  define MD5_ CC_MD5_
#else
#  include <openssl/md5.h>
#endif
#include "libft.h"

unsigned char *md5_original(void *data, size_t len)
{
	unsigned char *digest;
	struct MD5Context context;
	char md5string[33];
	int i;

	if (!(digest = malloc(16)))
		return (NULL);
	CC_MD5_Init(&context);
	CC_MD5_Update(&context, data, len);
	CC_MD5_Final(digest, &context);

	i = -1;
	while (++i < 16)
    	sprintf(&md5string[i*2], "%02x", (unsigned int)digest[i]);
    ft_printf("md5_original: \t%s\n", md5string);
	return (digest);
}