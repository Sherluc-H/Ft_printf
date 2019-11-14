/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:05:58 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/14 15:48:46 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_back_base(t_print_data data, unsigned long l, char *table, int base)
{
	int size;
	int precision_exist;
	int j;
	int max;

	j = 0;
	size = 0;
	precision_exist = 1;
	if (!data.precision)
	{
		precision_exist = 0;
		data.precision = l < 0 || (data.dot && data.precision == 0) ?
		ft_to_print_amount_base(l, base) - 1 : ft_to_print_amount_base(l, base);
		// if (l < 0 || (data.dot && data.precision == 0))
			// data.precision -= 1;
	}
	if (data.dot && data.precision == 0 && l == 0)
	{
		j--;
	}
	if (data.is_address)
	{
		// data.precision += 2;
		j+=2;
		size += 2;
	}
	if (l < 0)
	{
		data.precision++;
	}
	if (!data.found_zero || data.dot)
	{
		max = ft_to_print_amount_base(l, base) < data.precision ? data.precision : ft_to_print_amount_base(l, base);
		while (j < data.width - max)
		{
			write(1, " ", 1);
			size += 1;
			// data.precision++;
			j++;
		}
	}
	if (l < 0)
	{
		write(1, "-", 1);
		size += 1;
		l = -l;
	}
		//cas a gerer si on a 0 en precision il faut pas afficher 0 en int mais les autres il faut
	if (precision_exist || (!precision_exist && l != 0) || !data.dot)
		size += ft_to_print_amount_base(l, base);

	if (data.is_address)
	{
		write(1, "0x", 2);
		// size -= 2;
	}
	if (data.width < data.precision)
	{
		data.width = data.precision;
		if (data.is_address)
			data.width += 2;
	}
				// printf("size  = %d %d", size, data.width);
	while (size < data.width)
	{
		write(1, "0", 1);
		size += 1;
		data.precision++;
	}
	if (precision_exist || (!precision_exist && l != 0) || !data.dot)
		ft_putnbr_base(l, table, base);
	return (size);
}

int		ft_print_front_base(t_print_data data, unsigned long l, char *table, int base)
{
	int size;
	int precision_exist;
	int j;
	int max;

	size = 0;
	j = 0;
	precision_exist = 1;
	if (!data.precision)
	{
		precision_exist = 0;
		data.precision = l < 0 || (data.dot && data.precision == 0) ?
		ft_to_print_amount_base(l, base) - 1 : ft_to_print_amount_base(l, base);
		
		// data.precision = ft_to_print_amount_base(l, base);
		// if (l < 0 || (data.dot && data.precision == 0))
		// 	data.precision -= 1;
	}
	if (data.dot && data.precision == 0 && l == 0)
	{
		j--;
	}
	if (l < 0)
	{
		write(1, "-", 1);
		size += 1;
		data.precision++;
		j++;
		l = -l;
	}
	if (precision_exist || (!precision_exist && l != 0) || !data.dot)
		size += ft_to_print_amount_base(l, base);
	// printf("size here = %d %d", size, data.precision);
	if (data.is_address)
	{
		write(1, "0x", 2);
	}
	while (size < data.precision)
	{
		write(1, "0", 1);
		size += 1;
	}
	if (data.is_address)
	{
		// data.precision += 2;
		j+=2;
		size += 2;
	}
	if (precision_exist || (!precision_exist && l != 0) || !data.dot)
		ft_putnbr_base(l, table, base);
			// printf("size here = %d %d", size, data.precision);

	max = ft_to_print_amount_base(l, base) < data.precision ? data.precision : ft_to_print_amount_base(l, base);
		// printf("data here = %d %d", data.width, max);

	while (j < data.width - max)
	{
		write(1, " ", 1);
		size += 1;
		j++;
	}	
	return (size);
}

int		ft_print_base(t_print_data t_p_data, unsigned long l, char *table)
{
	if (t_p_data.found_minus)
		return (ft_print_front_base(t_p_data, l, table, t_p_data.converter == 'u' ? 10 : 16));
	else
		return (ft_print_back_base(t_p_data, l, table, t_p_data.converter == 'u' ? 10 : 16));
}

int ft_get_flags_data(t_print_data *t_p_data, char converter, va_list p, t_cut *cut)
{
	va_list p_copy;
	int i;

	i = 0;
	t_p_data->converter = converter;
	t_p_data->is_address = converter == 'p' ? 1 : 0;
	va_copy(p_copy, p);
	t_p_data->found_minus = ft_found_minus(cut->str, converter);
	t_p_data->found_zero = ft_found_zero_for_char(cut->str, converter);
	if ((t_p_data->precision = ft_precision(cut->str, converter, 0, 0, p_copy)) == -1)
		return (-1);
	va_copy(p_copy, p);
	if ((t_p_data->width = ft_width(cut->str, t_p_data, p_copy, 0)) == -1)
		return (-1);
	// printf("precision%d", t_p_data->precision);
	// printf("width=%d|\n", t_p_data->width);
	va_end(p_copy);
	t_p_data->dot = 0;
	while ((cut->str)[i] != converter)
	{
		if ((cut->str)[i] == '*')
			va_arg(p, int);
		else if ((cut->str)[i] == '.')
			t_p_data->dot = 1;
		i++;
	}
	return (1);
}

int		ft_printnbr_base(char converter, va_list p, t_cut *cut)
{
	t_print_data t_p_data;

	if ((ft_get_flags_data(&t_p_data, converter, p, cut)) == -1)
		return (-1);
	if (converter == 'p')
		return (ft_print_base(t_p_data, (unsigned long)va_arg(p, void*), "0123456789abcdef"));
	else if (converter == 'u')
		return (ft_print_base(t_p_data, (unsigned long)va_arg(p, unsigned int), "0123456789"));
	else if (converter == 'x')
		return (ft_print_base(t_p_data, (unsigned long)va_arg(p, unsigned int), "0123456789abcdef"));
	else if (converter == 'X')
		return (ft_print_base(t_p_data, (unsigned long)va_arg(p, unsigned int), "0123456789ABCDEF"));
	return (-1);
}
