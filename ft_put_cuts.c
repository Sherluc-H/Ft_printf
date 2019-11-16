/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:55:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 17:56:08 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_back(t_print_data data, int n)
{
	int size;
	int precision_exist;
	unsigned int ui;
	int max;
	int j;
	
	j = 0;
	size = 0;
	precision_exist = 1;
	if (!data.precision)
	{
		precision_exist = 0;
		// data.precision = n < 0 ? ft_to_print_amount(n) - 1 : ft_to_print_amount(n);
		data.precision = n < 0 || (data.dot && data.precision == 0) ?
		ft_to_print_amount(n) - 1 : ft_to_print_amount(n);
		// data.precision = ft_to_print_amount(n);
		// if (n < 0 || (data.dot && data.precision == 0))
		// 	data.precision -= 1;
	}
	if (data.dot && data.precision == 0 && n == 0)
	{
		j--;
	}
	if (n < 0)
	{
		ui = -n;
		data.precision++;
	}
	else
		ui = n;
	if (!data.found_zero || data.dot)
	{
		max = ft_to_print_amount(n) < data.precision ? data.precision : ft_to_print_amount(n);
		while (j < data.width - max)
		{
			write(1, " ", 1);
			size += 1;
			data.precision++;
			j++;
		}
	}
		//cas a gerer si on a 0 en precision il faut pas afficher 0 en int mais les autres il faut
	if (precision_exist || (!precision_exist && n != 0) || !data.dot)
		size += ft_to_print_amount_base(ui, 10);
	if (data.width < data.precision)
	{
		data.width = data.precision;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		size += 1;
	}
	while (size < data.width)
	{
		write(1, "0", 1);
		size += 1;
		data.precision++;
	}
	if (precision_exist || (!precision_exist && n != 0) || !data.dot)
		ft_putnbr_base(ui, "0123456789", 10);
	return (size);
}

int		ft_print_front(t_print_data data, int n)
{
	int size;
	int precision_exist;
	unsigned int ui;
	int j;
	int max;

	j = 0;

	size = 0;
	precision_exist = 1;
	if (!data.precision)
	{
		precision_exist = 0;
		data.precision = n < 0 || (data.dot && data.precision == 0) ?
		ft_to_print_amount(n) - 1 : ft_to_print_amount(n);
		// data.precision = ft_to_print_amount(n);
		// if (n < 0 || (data.dot && data.precision == 0))
		// 	data.precision -= 1;
		// 	// (data.precision && data.dot) || 
	}
	if (data.dot && data.precision == 0 && n == 0)
	{
		j--;
	}
	if (n < 0)
	{
		ui = -n;
		if (data.precision< ft_to_print_amount_base(ui, 10))
			data.precision = ft_to_print_amount_base(ui, 10);
		data.precision++;
		// j++;
		size += 1;
		write (1, "-", 1);
	}
	else
		ui = n;
	if (precision_exist || (!precision_exist && n != 0) || !data.dot)
		size += ft_to_print_amount_base(ui, 10);
	while (size < data.precision)
	{
		write(1, "0", 1);
		size += 1;
	}
	if (precision_exist || (!precision_exist && n != 0) || !data.dot)
		ft_putnbr_base(ui, "0123456789", 10);
			// printf("width=%d|\n", data.width);
	max = ft_to_print_amount_base(ui, 10) < data.precision ? data.precision : ft_to_print_amount_base(ui, 10);
			// printf("data here = %d %d", data.width, max);

	while (j < data.width - max)
	{
		write(1, " ", 1);
		size += 1;
		j++;
	}	
	return (size);
}

int		ft_printnbr(char converter, va_list p, t_cut *cut)
{
	int i;
	int n;
	// unsigned long l;
	t_print_data t_p_data;

	i = 0;
	if ((ft_get_flags_data(&t_p_data, converter, p, cut)) == -1)
		return (-1);
	n = va_arg(p, int);

	if (t_p_data.found_minus)
		return (ft_print_front(t_p_data, n));
	else
		return (ft_print_back(t_p_data, n));
}
