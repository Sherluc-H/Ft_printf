/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:55:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/09 19:12:32 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	ft_putstr(char *s)
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

int		ft_precision(char *str, char converter, int i, int j)
{
	char *width_str;//quand ya plusieur .x

	width_str = NULL;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '.' && ft_is_number(str[i + 1]))
		{
			i++;
			while (ft_is_number(str[i + j]))
				j++;
			width_str = malloc(sizeof(char) * (j + 1));
			j = 0;
			i = i - j;
			while (ft_is_number(str[i]))
			{
				width_str[j] = str[i];
				j++;
				i++;
			}
			width_str[j] = '\0';
		}
		i++;
	}
	return (ft_atoi_simple(width_str));
}

int		ft_width(char *str, char converter, va_list p_copy, int i)
{
	int precision;
	char *precision_width;
	int j;

	j = 0;
	precision = 0;
	precision_width = NULL;
	while (str[i] && str[i] != converter)
	{
		if(str[i] == '*')
		{
			i++;
			precision = va_arg(p_copy, int);
			if(!ft_is_number(str[i]))
				return (precision);
			else
			{
				while (ft_is_number(str[i + j]))
					j++;
				precision_width = malloc(sizeof(char) * (j + 1));
				j = 0;
				i = i - j;
				while (ft_is_number(str[i]))
				{
					precision_width[j] = str[i];
					j++;
					i++;
				}
				precision_width[j] = '\0';
			}
		}
		i++;
	}
	return (ft_atoi_simple(precision_width));
}

int		ft_print_back(int *size, int precision, int width, int n)
{
	while (precision + *size < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
	}
	if (n < 0)//ne marche pas encore
	{
		write(1, "-", 1);
		*size = *size + 1;
		width++;
		n = -n;
	}
	*size = *size + ft_to_print_amount(n);
	while (*size < width)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
	ft_putnbr(n);
	return (*size);
}

int		ft_print_front(int *size, int precision, int width, int n)
{
	int j;

	j = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		*size = *size + 1;
		precision++;
		n = -n;
	}
	*size = *size + ft_to_print_amount(n);
	while (*size < precision)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
	ft_putnbr(n);
	while (precision + j < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
		j++;
	}	
	return (*size);
}

char	ft_found_minus(char *str, char converter)
{
	int i;

	i = 0;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		ft_printnbr(char converter, va_list p_copy, t_cut *cut)
{
	int size;
	int width;
	int precision;
	int found_minus;
	int n;

	size = 0;
	found_minus = ft_found_minus(cut->str, converter);
	width = ft_width(cut->str, converter, p_copy, 0);
	precision = ft_precision(cut->str, converter, 0, 0);
	n = va_arg(p_copy, int);
	if (n<0)
	{

	}
	if (found_minus)
		ft_print_front(&size, precision, width, n);
	else
		ft_print_back(&size, precision, width, n);
	return (size);
}
