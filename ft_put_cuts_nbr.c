/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:05:58 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:25:41 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_back_base(t_print_data data, unsigned long l,
			char *table, int base)
{
	int size;
	int j;
	int max;

	j = 0;
	size = 0;
	ft_prepare_long(&data, l, &j, base);
	j += data.is_address ? 2 : 0;
	size += data.is_address ? 2 : 0;
	if (!data.found_zero || data.dot)
	{
		max = ft_to_print_amount_base(l, base) < data.precision ?
			data.precision : ft_to_print_amount_base(l, base);
		ft_add_space_nbr(data, &size, &j, max);
	}
	if (data.precision_exist || (!data.precision_exist && l != 0) || !data.dot)
		size += ft_to_print_amount_base(l, base);
	ft_add_zeros_nbr_back(&data, &size);
	if (data.precision_exist || (!data.precision_exist && l != 0) || !data.dot)
		ft_putnbr_base(l, table, base);
	return (size);
}

int			ft_print_front_base(t_print_data data, unsigned long l,
			char *table, int base)
{
	int size;
	int j;
	int max;

	size = 0;
	j = 0;
	ft_prepare_long(&data, l, &j, base);
	if (data.precision_exist || (!data.precision_exist && l != 0) || !data.dot)
		size += ft_to_print_amount_base(l, base);
	ft_add_zeros_nbr_front(&data, &size);
	j += data.is_address ? 2 : 0;
	size += data.is_address ? 2 : 0;
	if (data.precision_exist || (!data.precision_exist && l != 0) || !data.dot)
		ft_putnbr_base(l, table, base);
	max = ft_to_print_amount_base(l, base) < data.precision ?
		data.precision : ft_to_print_amount_base(l, base);
	ft_add_space_nbr(data, &size, &j, max);
	return (size);
}
