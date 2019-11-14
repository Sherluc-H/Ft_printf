/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:48:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/14 16:52:05 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_found_minus(char *str, char converter)
{
	int i;

	i = 0;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

char	ft_found_zero_for_char(char *str, char converter)
{
	int i;
	int found;

	i = 0;
	found = 0;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '0' && !ft_is_number(str[i - 1]) && str[i - 1] != '.')
			found = 1;
		i++;
	}
	return (found);
}

int		ft_precision(char *str, char converter, int i, int j, va_list p_copy)
{
	char *precision_str;
	int precision;
	int new_precision;
	int num_last;

	precision = 0;
	precision_str = NULL;
	new_precision = 0;
	num_last = 0;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '*')
		{
			va_arg(p_copy, int);
			// printf("p=%d", precision);

		}
		if (str[i] == '.' && ft_is_number(str[i + 1]))
		{
			i++;
			while (ft_is_number(str[i + j]))
				j++;
			if (!(precision_str = malloc(sizeof(char) * (j + 1))))
				return (-1);
			j = 0;
			i = i - j;
			while (ft_is_number(str[i]))
			{
				precision_str[j] = str[i];
				j++;
				i++;
			}
			i--;
			precision_str[j] = '\0';
			new_precision = ft_atoi_simple(precision_str);
			num_last = 1;
		}
		else if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
			{
				if ((new_precision = va_arg(p_copy, int)))
					precision = new_precision;
				//if < 0, precision = 0
				if (precision < 0)
					precision = 0;
				num_last = 0;
				i++;
				while (str[i] == '*')
				{
					va_arg(p_copy, int);
					i++;

				}
			}
			i--;
		}
		i++;
	}
	if (num_last)
		return (new_precision);
	return (precision);
}

int		ft_width(char *str, t_print_data *t_p_data, va_list p_copy, int i)
{
	int width;
	char *width_str;
	int new_width;
	int j;
	int num_last;
	int tmp;

	j = 0;
	width = 0;
	new_width = 0;
	width_str = NULL;
	num_last = 0;
	if (t_p_data->converter == '%')
		i++;
	while (str[i] && str[i] != t_p_data->converter)
	{
		if (ft_is_number(str[i]) && str[i - 1] != '*' && str[i - 1] != '.')
		{
			while (ft_is_number(str[i + j]))
				j++;
			if (!(width_str = malloc(sizeof(char) * (j + 1))))
				return (-1);
			j = 0;
			i = i - j;
			while (ft_is_number(str[i]))
			{
				width_str[j] = str[i];
				j++;
				i++;
			}
			width_str[j] = '\0';
			if ((tmp = ft_atoi_simple(width_str)) != 0)
			{
				new_width = tmp;
				num_last = 1;
			}
		}
		if (str[i] == '.')
		{
			i++;
			while (ft_is_number(str[i]))
				i++;
		}
				// if (str[i] == '*')
		if (str[i] == '*' && str[i - 1] != '.')
		{
			if ((new_width = va_arg(p_copy, int)))
				width = new_width;
			//si width < 0 il faut donner la valeur positif
			if (width < 0)
			{
				width = -width;//le - sera vu comme un flag -
				t_p_data->found_minus = 1;
			}
			num_last = 0;
		}
		if (str[i] == '*' && str[i - 1] == '.')
			va_arg(p_copy, int);
		if(str[i] == '*' && ft_is_number(str[i + 1]))
		{
			i++;
			while (ft_is_number(str[i + j]))
				j++;
			if (!(width_str = malloc(sizeof(char) * (j + 1))))
				return (-1);
			j = 0;
			i = i - j;
			while (ft_is_number(str[i]))
			{
				width_str[j] = str[i];
				j++;
				i++;
			}
			i--;
			width_str[j] = '\0';
			if ((tmp = ft_atoi_simple(width_str)) != 0)
			{
				new_width = tmp;
				num_last = 1;
			}
			// new_width = ft_atoi_simple(width_str);
		}
		i++;
	}
				// printf("wid=%d %d %d||\n", width, new_width, num_last);
	if (num_last)
		return (new_width);
	return (width);
}
