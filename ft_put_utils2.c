/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:34:51 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 11:41:56 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	unsigned int a;

	if (n < 0)
	{
		a = -n;
		ft_putchar('-');
	}
	else
		a = n;
	if (a >= 10)
	{
		ft_putnbr(a / 10);
		ft_putchar(a % 10 + 48);
	}
	else
		ft_putchar(a % 10 + 48);
}

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

int		ft_to_print_amount(int n)
{
	unsigned int	a;
	int				i;

	i = 0;
	if (n < 0)
	{
		a = -n;
		i++;
	}
	else
		a = n;
	while (a >= 10)
	{
		a = a / 10;
		i++;
	}
	return (i + 1);
}

int		ft_to_print_amount_base(unsigned long l, int base)
{
	unsigned long	a;
	int				i;

	i = 0;
	a = l;
	while (a >= (unsigned long)base)
	{
		a = a / base;
		i++;
	}
	return (i + 1);
}
