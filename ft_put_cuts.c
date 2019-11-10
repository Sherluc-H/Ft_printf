/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:55:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/10 20:15:37 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_back(int *size, int precision, int width, int n, int precision_exist)
{
	if (n < 0)
		precision++;
	while (precision + *size < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*size = *size + 1;
		n = -n;
	}
	//cas a gerer si on a 0 en precision il faut pas afficher 0 en int mais les autres il faut
	if (!precision_exist || (precision_exist && ((precision || n != 0) || !precision_exist)))
		*size = *size + ft_to_print_amount(n);
	while (*size < width)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
	if (!precision_exist || (precision_exist && ((precision || n != 0) || !precision_exist)))
		ft_putnbr(n);
	return (*size);
}

int		ft_print_front(int *size, int precision, int width, int n, int precision_exist)
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
	if (!precision_exist || (precision_exist && ((precision || n != 0) || !precision_exist)))
		*size = *size + ft_to_print_amount(n);
	while (*size < precision)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
	if (!precision_exist || (precision_exist && ((precision || n != 0) || !precision_exist)))
		ft_putnbr(n);
	while (precision + j < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
		j++;
	}	
	return (*size);
}

int		ft_printnbr(char converter, va_list p_copy, t_cut *cut)
{
	int size;
	int width;
	int precision;
	int precision_exist;
	int found_minus;
	int n;
	va_list p_copy2;

	size = 0;
	precision_exist = 0;
	va_copy(p_copy2, p_copy);
	found_minus = ft_found_minus(cut->str, converter);
	precision = ft_precision(cut->str, converter, 0, 0, &precision_exist, p_copy2);
	va_end(p_copy2);
	width = ft_width(cut->str, converter, p_copy, 0);
	n = va_arg(p_copy, int);
	if (found_minus)
		ft_print_front(&size, precision, width, n, precision_exist);
	else
		ft_print_back(&size, precision, width, n, precision_exist);
	return (size);
}

int		ft_print_back_char(int *size, int width, int n, char to_add)
{
	while (*size < width - 1)
	{
		write(1, &to_add, 1);
		*size = *size + 1;
	}
	ft_putchar(n);
	*size = *size + 1;
	return (*size);
}

int		ft_print_front_char(int *size, int width, int n, char to_add)
{
	ft_putchar(n);
	*size = *size + 1;
	while (*size < width)
	{
		write(1, &to_add, 1);
		*size = *size + 1;
	}	
	return (*size);
}

int		ft_print_back_str(int width, int precision, char *str, char to_add)
{
	int size;
	char *nul;
	int i;

	i = 0;
	nul = "(null)";
	size = 0;
	if (str)
	{
		if (precision > ft_strlenght(str))
			precision = ft_strlenght(str);
		while (size < width - precision)
		{
			write(1, &to_add, 1);
			size++;
		}
		size += ft_putstr(str);
		return (size);
	}
	if (precision > 6)
		precision = 6;
	while (size < width - precision)
	{
		write(1, &to_add, 1);
		size++;
	}
	while (i < precision)
	{
		write (1, &nul[i], 1);
		i++;
	}
	return (size + precision);
}

int		ft_print_front_str(int width, int precision, char *str, char to_add)
{
	int size;
	char *nul;
	int i;

	i = 0;
	nul = "(null)";
	size = 0;
	if (str)
	{
		size += ft_putstr(str);
		while (size < width)
		{
			write(1, &to_add, 1);
			size++;
		}	
		return (size);
	}
	if (precision > 6)
		precision = 6;
	while (i < precision)
	{
		write (1, &nul[i], 1);
		i++;
	}
	while (size + precision < width)
	{
		write(1, &to_add, 1);

		size++;
	}	
	return (size + precision);
}

int		ft_printchar(char converter, va_list p_copy, t_cut *cut)
{
	int width;
	int found_minus;
	int found_zero;
	char to_add;
	int n;
	int size;

	size = 0;
	n = 0;
	to_add = ' ';
	found_zero = ft_found_zero_for_char(cut->str, converter);
	found_minus = ft_found_minus(cut->str, converter);
	if (found_minus)
		found_zero = 0;
	else if (found_zero)
		to_add = '0';
	width = ft_width(cut->str, converter, p_copy, 0);
	if (converter == '%')
		n = '%';
	else if (converter == 'c')
		n = va_arg(p_copy, int);
	if (found_minus)
		return (ft_print_front_char(&size, width, n, to_add));
	else
		return (ft_print_back_char(&size, width, n, to_add));
}

int		ft_printstr(char converter, va_list p_copy, t_cut *cut)
{
	int width;
	int precision;
	int found_minus;
	int found_zero;
	char to_add;
	int size;
	va_list p_copy2;
	int precision_exist;

	size = 0;
	to_add = ' ';
	precision_exist = 0;
	found_zero = ft_found_zero_for_char(cut->str, converter);
	found_minus = ft_found_minus(cut->str, converter);
	if (found_minus)
		found_zero = 0;
	else if (found_zero)
		to_add = '0';
	va_copy(p_copy2, p_copy);
	precision = ft_precision(cut->str, converter, 0, 0, &precision_exist, p_copy2);
	va_end(p_copy2);
	width = ft_width(cut->str, converter, p_copy, 0);
	if (found_minus)
		return (ft_print_front_str(width, precision, va_arg(p_copy, char*), to_add));
	else
		return (ft_print_back_str(width, precision, va_arg(p_copy, char*), to_add));
}