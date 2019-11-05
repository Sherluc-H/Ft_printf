/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:55:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/30 17:55:59 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base(unsigned long l, char const *table, int base)
{
	if (l > (unsigned long)base - 1)
	{
		ft_putnbr_base(l / base, table, base);
		write(1, &table[l % base], 1);
	}
	else
		write(1, &table[l % base], 1);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putchar_fd(n % 10 + 48, 1);
	}
	else
		ft_putchar_fd(n % 10 + 48, 1);
}

void	ft_putaddress(void *p)
{
	unsigned long l;

	l = (unsigned long)p;
	write(1, "0x", 2);
	ft_putnbr_base(l, "0123456789abcdef", 16);
}
