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
    if (new_size - 8 <= size) // 8 for size_t + 1 for required minimal padding
        new_size += 64;

    //ft_printf("size %% 512= %zu, hence needs %zu to reach 448 and %zu with size so should be %zu but is %zu\n",
    //    size * 8 % 512, 448 - size * 8 % 512, 448 - size * 8 % 512 + 64, size * 8 + (448 - size * 8 % 512) + 64, new_size * 8);
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
    ft_memcpy(tmp->uchar, *words, size); // seems to go to far and override size ?!
    tmp->uchar[size] = LEADING_ONE; // append bit 1 right after
    
    tmp->uint64[new_size / 8 - 1] = (*(uint64_t *)&size);


    
    //ft_printf("written size is %lld when size was %lld\n", *((uint64_t *)(tmp->uchar + new_size - 8)), size);

    //free(*words);
    *words = tmp;
    return (new_size);
}