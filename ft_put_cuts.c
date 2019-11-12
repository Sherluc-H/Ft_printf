/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cuts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:55:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/11 19:37:37 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_back(int *size, int precision, int width, int n, int dot)
{
	int precision_exist;

	precision_exist = 1;
	if (!precision)
	{
		precision_exist = 0;
		precision = ft_to_print_amount(n);
		if ((precision && dot) || n < 0)
			precision -= 1;
	}
	if (n < 0)
	{
		precision++;
	}
	while (precision < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
		precision++;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*size = *size + 1;
		n = -n;
	}
		//cas a gerer si on a 0 en precision il faut pas afficher 0 en int mais les autres il faut
	if (precision_exist || (!precision_exist && n != 0) || !dot)
		*size = *size + ft_to_print_amount(n);
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
	if (precision_exist || (!precision_exist && n != 0) || !dot)
		ft_putnbr(n);
	return (*size);
}

int		ft_print_front(int *size, int precision, int width, int n, int dot)
{
	int precision_exist;

	precision_exist = 1;
	if (!precision)
	{
		precision_exist = 0;
		precision = ft_to_print_amount(n);
		if ((precision && dot) || n < 0)
			precision -= 1;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*size = *size + 1;
		precision++;
		n = -n;
	}
	if (precision_exist || (!precision_exist && n != 0) || !dot)
		*size = *size + ft_to_print_amount(n);
	while (*size < precision)
	{
		write(1, "0", 1);
		*size = *size + 1;
	}
	if (precision_exist || (!precision_exist && n != 0) || !dot)
		ft_putnbr(n);
	while (precision < width)
	{
		write(1, " ", 1);
		*size = *size + 1;
		precision++;
	}	
	return (*size);
}

int		ft_printnbr(char converter, va_list p_copy, t_cut *cut)
{
	int size;
	int width;
	int precision;
	int found_minus;
	int n;
	va_list p_copy2;
	int i;
	int dot;

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
	// printf("width%d", width);
	va_end(p_copy2);
	while ((cut->str)[i] != converter && (cut->str)[i])
	{
		if ((cut->str)[i] == '*')
			va_arg(p_copy, int);
		i++;
	}
	i = 0;
	n = va_arg(p_copy, int);
	if (n == 0)
	{
		while ((cut->str)[i] != converter)
		{
			if ((cut->str)[i] == '.')
				dot = 1;
			i++;
		}
	}
	if (found_minus)
		ft_print_front(&size, precision, width, n, dot);
	else
		ft_print_back(&size, precision, width, n, dot);
	return (size);
}

int		ft_print_back_char(int *size, int width, int n, char to_add)
{
	while (*size < width - 1)
	{
		write(1, &to_add, 1);
		*size = *size + 1;
	}
	ft_putchar((unsigned char)n);
	*size = *size + 1;
	return (*size);
}

int		ft_print_front_char(int *size, int width, int n, char to_add)
{
	ft_putchar((unsigned char)n);
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
	if ((width = ft_width(cut->str, converter, p_copy, 0)) == -1)
		return (-1);
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

	size = 0;
	to_add = ' ';
	found_zero = ft_found_zero_for_char(cut->str, converter);
	found_minus = ft_found_minus(cut->str, converter);
	if (found_minus)
		found_zero = 0;
	else if (found_zero)
		to_add = '0';
	va_copy(p_copy2, p_copy);
	if ((precision = ft_precision(cut->str, converter, 0, 0, p_copy2)) == -1)
		return (-1);
	va_end(p_copy2);
	if ((width = ft_width(cut->str, converter, p_copy, 0)) == -1)
		return (-1);
	if (found_minus)
		return (ft_print_front_str(width, precision, va_arg(p_copy, char*), to_add));
	else
		return (ft_print_back_str(width, precision, va_arg(p_copy, char*), to_add));
}