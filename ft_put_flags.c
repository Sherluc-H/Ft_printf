/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:48:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/11 19:27:00 by lhuang           ###   ########.fr       */
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

int		ft_width(char *str, char converter, va_list p_copy, int i)
{
	int width;
	char *width_str;
	int new_width;
	int j;
	int num_last;

	j = 0;
	width = 0;
	new_width = 0;
	width_str = NULL;
	num_last = 0;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '*')
		{
			if ((new_width = va_arg(p_copy, int)))
			width = new_width;
			num_last = 0;
			// printf("wid=%d", width);
		}
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
			new_width = ft_atoi_simple(width_str);
			num_last = 1;
		}
		i++;
	}
	if (num_last)
		return (new_width);
	return (width);
}
