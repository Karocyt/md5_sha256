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
    //uint32_t    *words;
    size_t      new_size;

    new_size = (size / 64 + 1) * 64; // %64 should be 56, but we'll need to append a size_t so should equals 0
    if (new_size - 9 <= size) // 8 for size_t + 1 for required minimal padding
        new_size += 64;
    //ft_printf("size bits: %zu, size %%512bits: %zu\nnew_size bits: %zu, new_size %%512bits: %zu\n", size*8, size*8 % 512, new_size*8, new_size*8 % 512);
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
    //ft_printf("CRAZY SIZE: %zu\n", size);
    //ft_printf("old_size = %zu, new_size = %zu, tmp = %p, size/8 = %zu, offset = %zu\n", size, new_size, &tmp, size / 8, size / 8 * 8);
    ft_memcpy(tmp->uchar, *words, size); // seems to go to far and override size ?!
    tmp->uchar[size] = LEADING_ONE; // append bit 1 right after
    tmp->uint32[new_size / 4 - 2] = ((uint32_t *)&size)[0];
    tmp->uint32[new_size / 4 - 1] = ((uint32_t *)&size)[1];

    //tmp->uint32[size / 4 - 2] = ((uint32_t *)&size)[1];
    //tmp->uint32[size / 4 - 1] = ((uint32_t *)&size)[0];


    ft_memcpy(tmp->uchar + new_size - sizeof(size_t), &size, sizeof(size_t)); // write size at end
    
    //ft_printf("written size is %lld when size was %lld\n", *((uint64_t *)(tmp->uchar + new_size - 8)), size);

    free(*words);
    *words = tmp;
    return (new_size);
}