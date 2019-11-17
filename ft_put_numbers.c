/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:16:41 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:27:58 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printnbr(char converter, va_list p, t_cut *cut)
{
	int				i;
	int				n;
	t_print_data	t_p_data;

	i = 0;
	if ((ft_get_flags_data(&t_p_data, converter, p, cut)) == -1)
		return (-1);
	n = va_arg(p, int);
	if (t_p_data.found_minus)
		return (ft_print_front(t_p_data, n));
	else
		return (ft_print_back(t_p_data, n));
}

static int	ft_print_base(t_print_data t_p_data, unsigned long l, char *table)
{
	if (t_p_data.found_minus)
		return (ft_print_front_base(t_p_data, l, table,
				t_p_data.converter == 'u' ? 10 : 16));
	else
		return (ft_print_back_base(t_p_data, l, table,
				t_p_data.converter == 'u' ? 10 : 16));
}

int			ft_printnbr_base(char converter, va_list p, t_cut *cut)
{
	t_print_data t_p_data;

	if ((ft_get_flags_data(&t_p_data, converter, p, cut)) == -1)
		return (-1);
	if (converter == 'p')
		return (ft_print_base(t_p_data,
				(unsigned long)va_arg(p, void*), "0123456789abcdef"));
	else if (converter == 'u')
		return (ft_print_base(t_p_data,
				(unsigned long)va_arg(p, unsigned int), "0123456789"));
	else if (converter == 'x')
		return (ft_print_base(t_p_data,
				(unsigned long)va_arg(p, unsigned int), "0123456789abcdef"));
	else if (converter == 'X')
		return (ft_print_base(t_p_data,
				(unsigned long)va_arg(p, unsigned int), "0123456789ABCDEF"));
	else
		return (-1);
}
