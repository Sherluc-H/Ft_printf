/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:37:02 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/10 15:47:23 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlenght(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int n)
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

int		ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
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

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n % 10 + 48);
}

void	ft_putaddress(void *p)
{
	unsigned long l;

	l = (unsigned long)p;
	write(1, "0x", 2);
	ft_putnbr_base(l, "0123456789abcdef", 16);
}

int		ft_atoi_simple(char *str)
{
	int i;
	unsigned int nb;

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

int		ft_to_print_amount(int n)
{
	unsigned int a;
	int i;

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