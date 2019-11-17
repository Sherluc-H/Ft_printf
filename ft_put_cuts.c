/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:55:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:30:11 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prepare(t_print_data *data, int n, int *j)
{
	data->precision_exist = 1;
	if (!data->precision)
	{
		data->precision_exist = 0;
		data->precision = n < 0 || (data->dot && data->precision == 0) ?
		ft_to_print_amount(n) - 1 : ft_to_print_amount(n);
	}
	if (data->dot && data->precision == 0 && n == 0)
		*j = *j - 1;
}

static void	ft_add_espace(t_print_data data, int n, int *j, int *size)
{
	int max;

	max = ft_to_print_amount(n) < data.precision ?
		data.precision : ft_to_print_amount(n);
	while (*j < data.width - max)
	{
		write(1, " ", 1);
		*size = *size + 1;
		*j = *j + 1;
	}
}

static void	ft_add_zeros_before(t_print_data data, int nb_limit,
			int *size, unsigned int ui)
{
	while (*size < nb_limit)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
	if (data.precision_exist || (!data.precision_exist && ui != 0) || !data.dot)
		ft_putnbr_base(ui, "0123456789", 10);
}

int			ft_print_back(t_print_data data, int n)
{
	int				size;
	unsigned int	ui;
	int				j;

	j = 0;
	size = 0;
	ft_prepare(&data, n, &j);
	ui = n < 0 ? -n : n;
	data.precision += n < 0 ? 1 : 0;
	if (!data.found_zero || data.dot)
		ft_add_espace(data, n, &j, &size);
	if (data.precision_exist || (!data.precision_exist && n != 0) || !data.dot)
		size += ft_to_print_amount_base(ui, 10);
	if (data.width < data.precision)
		data.width = data.precision;
	if (n < 0)
	{
		write(1, "-", 1);
		size += 1;
	}
	ft_add_zeros_before(data, data.width, &size, ui);
	return (size);
}

int			ft_print_front(t_print_data data, int n)
{
	int				size;
	unsigned int	ui;
	int				j;

	j = 0;
	size = 0;
	ft_prepare(&data, n, &j);
	if (n < 0)
	{
		ui = -n;
		if (data.precision < ft_to_print_amount_base(ui, 10))
			data.precision = ft_to_print_amount_base(ui, 10);
		data.precision++;
		size += 1;
		write(1, "-", 1);
	}
	else
		ui = n;
	if (data.precision_exist || (!data.precision_exist && n != 0) || !data.dot)
		size += ft_to_print_amount_base(ui, 10);
	ft_add_zeros_before(data, data.precision, &size, ui);
	ft_add_espace(data, n, &j, &size);
	return (size);
}
