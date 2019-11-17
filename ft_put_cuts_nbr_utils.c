/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts_nbr_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:19:38 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:30:40 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prepare_long(t_print_data *data, unsigned long l, int *j, int base)
{
	data->precision_exist = 1;
	if (!data->precision)
	{
		data->precision_exist = 0;
		data->precision = l < 0 || (data->dot && data->precision == 0) ?
		ft_to_print_amount_base(l, base) - 1 : ft_to_print_amount_base(l, base);
	}
	if (data->dot && data->precision == 0 && l == 0)
		*j = *j - 1;
}

void	ft_add_zeros_nbr_back(t_print_data *data, int *size)
{
	if (data->is_address)
		write(1, "0x", 2);
	if (data->width < data->precision)
	{
		data->width = data->precision;
		if (data->is_address)
			data->width = data->width + 2;
	}
	while (*size < data->width)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
}

void	ft_add_zeros_nbr_front(t_print_data *data, int *size)
{
	if (data->is_address)
		write(1, "0x", 2);
	while (*size < data->precision)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
}

void	ft_add_space_nbr(t_print_data data, int *size, int *j, int max)
{
	while (*j < data.width - max)
	{
		write(1, " ", 1);
		*size = *size + 1;
		*j = *j + 1;
	}
}
