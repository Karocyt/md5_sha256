/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:43:46 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:43:54 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/*
** - What it does :
** 		Append up to BUFF_SIZE chars read from fd to stack[fd]
** - How it does it :
**		Read to a buff string, finish it with a '/0', strcatdup a new stack and
** 		free the previous one.
** - Return values :
** 		1 if everything went fine, 0 otherwise.
*/

int			gnl_append_read(char **stack, int fd)
{
	char		buff[BUFF_SIZE + 1];
	char		*new_stack;
	int			read_status;

	if ((read_status = read(fd, buff, BUFF_SIZE)) <= 0)
		return (read_status);
	buff[read_status] = 0;
	if (!(new_stack = ft_strcatdup(*stack, buff)))
		return (-1);
	if (stack)
		free(*stack);
	*stack = new_stack;
	return (read_status > 0 ? 1 : read_status);
}

/*
** - What it does :
** 		Extract a full line and the new stack from the stack
** - How it does it :
**		strsub powaaaaa
** - Return values:
** 		len_line (at the stage where it still include '/n')
*/

static int	gnl_extract_line(char **stack, char *pos, char **line)
{
	size_t		len_stack;
	size_t		len_line;
	char		*old_stack;

	len_line = pos - *stack;
	len_stack = ft_strlen(*stack);
	old_stack = *stack;
	if (!(*line = ft_strsub(old_stack, 0, len_line)))
		return (0);
	if (old_stack[len_line] == '\n')
		*stack = ft_strsub(old_stack, len_line + 1, len_stack - len_line - 1);
	else
		*stack = ft_strsub(old_stack, len_line, len_stack - len_line);
	free(old_stack);
	return (len_line);
}

/*
** - What it does :
**  	Fetches the next line on a file descriptor without '\n'.
** - How it does it :
**  	While stack[fd] does not contains a full line, read more.
** 		If no '\n' was found, set the end of [stack] as end_of_line.
** 		Extract the line and set the new stack, free stack[fd]/stack
** 		if empty.
** - Return values:
**  	1 if a line was found, 0 if no more lines to read, -1 if errors.
*/

int			get_next_line(const int fd, char **line)
{
	static char		*stack[1024];
	char			*end_of_line;
	int				ret;
	int				last_read;

	if ((last_read = 1) && !line && stack[fd])
		ft_memdel((void **)&stack[fd]);
	ret = 1;
	if (!line || (!stack[fd] && (!(stack[fd] = ft_memalloc(1)))))
		return (-1);
	while (!(end_of_line = ft_strchr(stack[fd], '\n')) && last_read > 0
		&& (last_read = gnl_append_read(&stack[fd], fd)) != -42)
		if (last_read < 0)
			ret = last_read;
		else
			last_read ? ret++ : (ret += last_read - 1);
	if (!end_of_line)
		end_of_line = stack[fd] + ft_strlen(stack[fd]);
	ret = gnl_extract_line(&stack[fd], end_of_line, line) ? 1 : ret;
	if (ret < 1 && !ft_strlen(*line))
		ft_memdel((void **)&stack[fd]);
	return (ret > 1 ? 1 : ret);
}
