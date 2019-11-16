/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_characters2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:50:02 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 17:56:14 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_null_back(t_print_data data, char to_add, int i, int size)
{
	char	*nul;
	int		precision_zero;

	precision_zero = 0;
	nul = "(null)";
	if (data.precision == 0)
		precision_zero = 1;
	if (data.precision > 6 || (data.precision == 0 && !data.dot))
		data.precision = 6;
	while (size + data.precision < data.width)
	{
		write(1, &to_add, 1);
		size++;
	}
	if ((data.dot && !precision_zero) || !data.dot)
	{
		while (i < data.precision)
		{
			write(1, &nul[i], 1);
			i++;
		}
	}
	return (size + data.precision);
}

int		ft_print_back_str(t_print_data data, char *str, char to_add)
{
	int		size;
	char	*nul;
	int		i;
	int		precision_zero;

	precision_zero = 0;
	i = 0;
	nul = "(null)";
	size = 0;
	if (str)
	{
		if (!data.dot)
			data.precision = ft_strlenght(str);
		if (data.precision > ft_strlenght(str))
			data.precision = ft_strlenght(str);
		while (size < data.width - data.precision)
		{
			write(1, &to_add, 1);
			size++;
		}
		size += ft_putstr(str, data.precision);
		return (size);
	}
	return (ft_str_null_back(data, to_add, 0, 0));
}

int		ft_str_null_front(t_print_data data, char to_add, int i, int size)
{
	char	*nul;
	int		precision_zero;

	precision_zero = 0;
	nul = "(null)";
	if (data.precision == 0)
		precision_zero = 1;
	if (data.precision > 6 || (data.precision == 0 && !data.dot))
		data.precision = 6;
	if ((data.dot && !precision_zero) || !data.dot)
	{
		while (i < data.precision)
		{
			write(1, &nul[i], 1);
			i++;
		}
	}
	while (size + data.precision < data.width)
	{
		write(1, &to_add, 1);
		size++;
	}
	return (size + data.precision);
}

int		ft_print_front_str(t_print_data data, char *str, char to_add)
{
	int size;

	size = 0;
	if (str)
	{
		if (!data.dot)
			data.precision = ft_strlenght(str);
		size += ft_putstr(str, data.precision);
		while (size < data.width)
		{
			write(1, &to_add, 1);
			size++;
		}
		return (size);
	}
	return (ft_str_null_front(data, to_add, 0, 0));
}
