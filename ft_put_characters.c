/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_characters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:48:21 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 17:01:34 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int		ft_print_characteres(char converter, t_print_data t_p_data,
		va_list p, char to_add)
{
	if (t_p_data.found_minus)
	{
		if (converter == 's')
			return (ft_print_front_str(t_p_data, va_arg(p, char*), to_add));
		else
			return (ft_print_front_char(t_p_data,
					converter == 'c' ? va_arg(p, int) : '%', to_add));
	}
	else
	{
		if (converter == 's')
			return (ft_print_back_str(t_p_data, va_arg(p, char*), to_add));
		else
			return (ft_print_back_char(t_p_data,
					converter == 'c' ? va_arg(p, int) : '%', to_add));
	}
}

int		ft_printcharacteres(char converter, va_list p, t_cut *cut)
{
	t_print_data	t_p_data;
	char			to_add;

	if ((ft_get_flags_data(&t_p_data, converter, p, cut)) == -1)
		return (-1);
	to_add = ' ';
	if (t_p_data.found_minus)
		t_p_data.found_zero = 0;
	else if (t_p_data.found_zero)
		to_add = '0';
	return (ft_print_characteres(converter, t_p_data, p, to_add));
}
