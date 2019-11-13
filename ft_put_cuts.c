/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:55:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/13 19:41:58 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_back(t_print_data data, int n)
{
	int size;
	int precision_exist;
	unsigned int ui;

	size = 0;
	precision_exist = 1;
	if (!data.precision)
	{
		precision_exist = 0;
		data.precision = ft_to_print_amount(n);
		if ((data.precision && data.dot) || n < 0)
			data.precision -= 1;
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
		while (data.precision < data.width)
		{
			write(1, " ", 1);
			size += 1;
			data.precision++;
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

	size = 0;
	precision_exist = 1;
	if (!data.precision)
	{
		precision_exist = 0;
		data.precision = ft_to_print_amount(n);
		if ((data.precision && data.dot) || n < 0)
			data.precision -= 1;
	}
	if (n < 0)
	{
		ui = -n;
		data.precision++;
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
	while (data.precision < data.width)
	{
		write(1, " ", 1);
		size += 1;
		data.precision++;
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

int		ft_print_back_char(t_print_data data, int n, char to_add)
{
	int size;

	size = 0;
	while (size < data.width - 1)
	{
		write(1, &to_add, 1);
		size += 1;
	}
	ft_putchar((unsigned char)n);
	size += 1;
	return (size);
}

int		ft_print_front_char(t_print_data data, int n, char to_add)
{
	int size;

	size = 0;
	ft_putchar((unsigned char)n);
	size += 1;
	while (size < data.width)
	{
		write(1, &to_add, 1);
		size += 1;
	}	
	return (size);
}

int		ft_print_back_str(t_print_data data, char *str, char to_add)
{
	int size;
	char *nul;
	int i;

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
	if (data.precision > 6 || data.precision == 0)
		data.precision = 6;
	while (size + data.precision < data.width)
	{
		write(1, &to_add, 1);
		size++;
	}
	while (i < data.precision)
	{
		write (1, &nul[i], 1);
		i++;
	}
	return (size + data.precision);
}

int		ft_print_front_str(t_print_data data, char *str, char to_add)
{
	int size;
	char *nul;
	int i;

	i = 0;
	nul = "(null)";
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
	if (data.precision > 6 || data.precision == 0)
		data.precision = 6;
	while (i < data.precision)
	{
		write (1, &nul[i], 1);
		i++;
	}
	while (size + data.precision < data.width)
	{
		write(1, &to_add, 1);
		size++;
	}	
	return (size + data.precision);
}

int		ft_printcharacteres(char converter, va_list p, t_cut *cut)
{
	t_print_data t_p_data;
	char to_add;
	// int found_zero;

	if ((ft_get_flags_data(&t_p_data, converter, p, cut)) == -1)
		return (-1);
	// found_zero = ft_found_zero_for_char(cut->str, converter);
	to_add = ' ';
	if (t_p_data.found_minus)
		t_p_data.found_zero = 0;
	else if (t_p_data.found_zero)
		to_add = '0';
	if (t_p_data.found_minus)
	{
		if (converter == 's')
			return (ft_print_front_str(t_p_data, va_arg(p, char*), to_add));
		else
			return (ft_print_front_char(t_p_data, converter == 'c' ? va_arg(p, int) : '%', to_add));
	}
	else
	{
		if (converter == 's')
			return (ft_print_back_str(t_p_data, va_arg(p, char*), to_add));
		else
			return (ft_print_back_char(t_p_data, converter == 'c' ? va_arg(p, int) : '%', to_add));
	}
}