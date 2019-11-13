/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 11:15:59 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(const char *input, ...)
{
	char		*str;
	int			ret;
	va_list		ap;

	str = NULL;
	va_start(ap, input);
	ret = ft_main_printf(&str, input, ap);
	ft_putstr(str);
	free(str);
	va_end(ap);
	return (ret);
}

char		*ft_spf(const char *input, ...)
{
	char		*str;
	va_list		ap;

	str = NULL;
	va_start(ap, input);
	ft_main_printf(&str, input, ap);
	va_end(ap);
	free(str);
	return (str);
}

char		*ft_vspf(const char *input, va_list ap)
{
	char		*str;

	str = NULL;
	ft_main_printf(&str, input, ap);
	return (str);
}

int			ft_fprintf(int fd, const char *input, ...)
{
	char		*str;
	int			ret;
	va_list		ap;

	str = NULL;
	va_start(ap, input);
	ret = ft_main_printf(&str, input, ap);
	ft_putstr_fd(str, fd);
	free(str);
	va_end(ap);
	return (ret);
}

int			ft_vprintf(const char *input, va_list ap)
{
	char		*str;
	int			ret;

	str = NULL;
	ret = ft_main_printf(&str, input, ap);
	ft_putstr(str);
	free(str);
	return (ret);
}
