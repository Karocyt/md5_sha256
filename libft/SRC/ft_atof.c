/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 19:44:03 by kevazoul     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:44:03 by kevazoul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static double	ft_isinfinity(char *s)
{
	short	sign;

	if (!ft_strcmp(s, "NAN") || !ft_strcmp(s, "nan") || !ft_strcmp(s, "nAN") ||
		!ft_strcmp(s, "NaN") || !ft_strcmp(s, "NAn") || !ft_strcmp(s, "Nan") ||
		!ft_strcmp(s, "nAn") || !ft_strcmp(s, "naN"))
		return (FT_NOT_A_NUMBER);
	if (*s == '+' || *s == '-')
	{
		sign = (*s == '-') ? -1 : 1;
		s++;
	}
	if (!ft_strcmp(s, "INF") || !ft_strcmp(s, "iNF") || !ft_strcmp(s, "InF") ||
		!ft_strcmp(s, "INf") || !ft_strcmp(s, "Inf") || !ft_strcmp(s, "iNf") ||
		!ft_strcmp(s, "inF") || !ft_strcmp(s, "inf"))
		return (sign * (FT_INFINITY));
	return (0);
}

static double	ft_atod(char *str)
{
	double	nb;
	short	s;
	short	d;

	d = 0;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	s = (*str == '-') ? -1 : 1;
	(*str == '+' || *str == '-') ? str++ : 0;
	while (ft_isdigit(*str))
		nb = nb * 10 + (*str++ - 48);
	(*str == '.') ? str++ : 0;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (*str++ - 48);
		d++;
	}
	return (nb / (ft_pow(10, d)) * s);
}

static double	ft_e(char *s)
{
	double		res;
	short		e;

	e = ft_atod(s);
	res = (e < 0) ? 1 : 10;
	if (e > 0)
		while (e-- > 0)
			res *= 10;
	while (e++ < 0)
		res /= 10;
	return (res);
}

static char		*ft_jumpf(char *s)
{
	(*s == '+' || *s == '-') ? s++ : 0;
	while (ft_isspace(*s))
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
		while (ft_isdigit(*++s))
			s = (char *)s;
	return (s);
}

double			ft_atof(const char *nptr)
{
	char	*s;
	double	nb;

	if (!nptr)
		return (0);
	s = (char *)nptr;
	nb = ft_atod(s);
	if (ft_isinfinity(s))
		return (ft_isinfinity(s));
	s = ft_jumpf(s);
	if ((*s == 'e' || *s == 'E') && (ft_isdigit(*++s)
		|| *s == '+' || *s == '-'))
		nb = nb * ft_e(s);
	return (nb);
}
