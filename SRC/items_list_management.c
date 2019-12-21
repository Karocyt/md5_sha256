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

static void ssl_append_item(t_item **lst, t_item *new)
{
    t_item *curr;
    t_item **target;

    curr = *lst;
    target = lst;
    while (curr && (target = &curr->next))
        curr = curr->next;
    *target = new;
}

int        ssl_add_item_from_str(t_item **lst, char *str)
{
    t_item *new;
    size_t size;

    //ft_printf("add_item_from_str... ");
    size = ft_strlen(str);
    if (!(new = malloc(sizeof(t_item))))
        return (1);
    new->content = ft_strdup(str);
    new->size = size;
    new->next = NULL;
    ssl_append_item(lst, new);
    //ft_printf("OK\n");
    return (0);
}

int        ssl_add_item_from_fd(t_item **lst, int fd)
{
    t_item *new;
    unsigned char *content;
    size_t size;

    //ft_printf("add_item_from_fd...");
    if ((size = ft_get_fd_content(&content, fd)) < 0)
        return (0);
    if (!(new = malloc(sizeof(t_item))))
        return (1);
    new->content = content;
    new->size = size;
    new->next = NULL;
    ssl_append_item(lst, new);
    //ft_printf("OK\n");
    return (0);
}

void    ssl_clear_items(t_item **lst)
{
    t_item *next;
    t_item *curr;

    next = *lst;
    while ((curr = next))
    {
        next = curr->next;
        free(curr->content);
        free(curr);
    }
    *lst = NULL;
}