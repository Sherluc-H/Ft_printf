/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:37:02 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 17:56:01 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlenght(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *s, int precision)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && i < precision)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int		ft_atoi_simple(char *str)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	if (!str)
	{
		return (0);
	}
	while (ft_is_number(str[i]) && str[i])
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	free(str);
	return (nb);
}
