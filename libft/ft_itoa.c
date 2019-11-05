/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:34:00 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 12:23:31 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strreverse2(char *str)
{
	int		i;
	int		str_size;
	char	c;

	i = 0;
	str_size = ft_strlen1(str);
	while (i < str_size / 2)
	{
		c = str[str_size - i - 1];
		str[str_size - i - 1] = str[i];
		str[i] = c;
		i++;
	}
	return (str);
}

static int	ft_get_size_final(unsigned int n, int i)
{
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_create_str(unsigned int n, int i, int is_negative)
{
	char	*p;
	int		pos;

	pos = 0;
	if (!(p = malloc(i * sizeof(char) + 1)))
		return (NULL);
	p[i] = '\0';
	if (n == 0)
		p[pos] = '0';
	while (n > 0)
	{
		if (n % 10 == 0)
			p[pos] = '0';
		else
			p[pos] = n % 10 + 48;
		pos++;
		n = n / 10;
	}
	if (is_negative)
	{
		p[pos] = '-';
		pos++;
	}
	return (ft_strreverse2(p));
}

char		*ft_itoa(int n)
{
	int	i;
	int	is_negative;

	i = 1;
	is_negative = 0;
	if (n == -2147483648)
	{
		i++;
		is_negative = 1;
		return (ft_create_str(n, ft_get_size_final(n, i), is_negative));
	}
	if (n < 0)
	{
		i++;
		n = -n;
		is_negative = 1;
		return (ft_create_str(n, ft_get_size_final(n, i), is_negative));
	}
	return (ft_create_str(n, ft_get_size_final(n, i), is_negative));
}
