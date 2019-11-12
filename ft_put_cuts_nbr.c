/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:05:58 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/11 19:42:31 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int	ft_putaddress(char converter, va_list p, t_cut *cut)
{
	// unsigned long l;

	// l = (unsigned long)va_arg(p, void*);
	// write(1, "0x", 2);
	return (ft_printnbr_base(converter, p, cut));
	// ft_putnbr_base(l, "0123456789abcdef", 16);
	// return (1);
}


int		ft_print_back_base(int *size, int precision, int width, unsigned long l, int dot, int is_address)
{
	int precision_exist;

	precision_exist = 1;
	if (!precision)
	{
		precision_exist = 0;
		precision = ft_to_print_amount_base(l, 16);
		if ((precision && dot) || l < 0)
			precision -= 1;
	}
	if (is_address)
	{
		precision += 2;
		*size = *size + 2;
	}
	if (l < 0)
	{
		precision++;
	}
	while (precision < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
		precision++;
	}
	if (l < 0)
	{
		write(1, "-", 1);
		*size = *size + 1;
		l = -l;
	}
		//cas a gerer si on a 0 en precision il faut pas afficher 0 en int mais les autres il faut
	if (precision_exist || (!precision_exist && l != 0) || !dot)
		*size = *size + ft_to_print_amount_base(l, 16);

	if (is_address)
	{
		write(1, "0x", 2);
		// *size = *size + 2;
	}
		if (width < precision)
	{
		width = precision;
	}
	while (*size < width)
	{
		write(1, "0", 1);
		*size = *size + 1;
		precision++;
	}
	if (precision_exist || (!precision_exist && l != 0) || !dot)
		ft_putnbr_base(l, "0123456789abcdef", 16);
	return (*size);
}

int		ft_print_front_base(int *size, int precision, int width, unsigned long l, int dot, int is_address)
{
	int precision_exist;

	precision_exist = 1;
	if (!precision)
	{
		precision_exist = 0;
		precision = ft_to_print_amount_base(l, 16);
		if ((precision && dot) || l < 0)
			precision -= 1;
	}
	if (l < 0)
	{
		write(1, "-", 1);
		*size = *size + 1;
		precision++;
		l = -l;
	}
	if (precision_exist || (!precision_exist && l != 0) || !dot)
		*size = *size + ft_to_print_amount_base(l, 16);
	if (is_address)
	{
		write(1, "0x", 2);
	}
	while (*size < precision)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
	if (is_address)
	{
		precision += 2;
		*size = *size + 2;
	}
	if (precision_exist || (!precision_exist && l != 0) || !dot)
		ft_putnbr_base(l, "0123456789abcdef", 16);
	while (precision < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
		precision++;
	}	
	return (*size);
}

int		ft_printnbr_base(char converter, va_list p_copy, t_cut *cut)
{
	int size;
	int width;
	int precision;
	int found_minus;
	// int n;
	va_list p_copy2;
	int i;
	int dot;
	unsigned long l;
	int is_address;

	is_address = 0;
	if (converter == 'p')
		is_address = 1;
	dot = 0;
	i = 0;
	size = 0;
	va_copy(p_copy2, p_copy);
	found_minus = ft_found_minus(cut->str, converter);
	if ((precision = ft_precision(cut->str, converter, 0, 0, p_copy2)) == -1)
		return (-1);
	// printf("precision%d", precision);
	va_copy(p_copy2, p_copy);
	if ((width = ft_width(cut->str, converter, p_copy2, 0)) == -1)
		return (-1);
	// printf("width=%d|", width);
	va_end(p_copy2);
	while ((cut->str)[i] != converter && (cut->str)[i])
	{
		if ((cut->str)[i] == '*')
			va_arg(p_copy, int);
		i++;
	}
	i = 0;
	l = (unsigned long)va_arg(p_copy, void*);
	if (l == 0)
	{
		while ((cut->str)[i] != converter)
		{
			if ((cut->str)[i] == '.')
				dot = 1;
			i++;
		}
	}
	if (found_minus)
		ft_print_front_base(&size, precision, width, l, dot, is_address);
	else
		ft_print_back_base(&size, precision, width, l, dot, is_address);
	return (size);
}