/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:04 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 11:15:28 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

long int	ft_get_fd_content(unsigned char **res, int fd)
{
	long int		read_status;
	long int 		total_size;
	unsigned char	buff[BUFF_SIZE];

	total_size = 0;
	*res = NULL;
	while ((read_status = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(*res = ft_realloc2(*res, total_size, total_size + read_status)))
			return (-1);
		ft_memcpy(*res + total_size, buff, read_status);
		total_size += read_status;
	}
	if (fd > 2)
		close(fd);
	if (read_status == 0)
		return (total_size);
	if (*res)
		ft_memdel((void **)res);
	return (-1);
}
