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

static size_t md5_pad512_newsize(size_t size)
{
    size_t      new_size;

    new_size = (size / 64 + 1) * 64;
    if (new_size - 8 <= size)
        new_size += 8;
    return (new_size);

}

size_t md5_pad(t_md5_words **words, size_t size)
{
    size_t              new_size;
    t_md5_words         *tmp;

    if (!(tmp = malloc(sizeof(t_md5_words))))
        return (0);
    if (!(new_size = md5_pad512_newsize(size)))
        return (0);
    if (new_size < size || !(tmp->uchar = ft_memalloc(new_size)))
        return (0);
    ft_memcpy(tmp->uchar, *words, size);
    tmp->uchar[size] = LEADING_ONE;
    
    tmp->uint64[new_size / 8 - 1] = size * 8;
    free(*words);
    *words = tmp;
    return (new_size);
}