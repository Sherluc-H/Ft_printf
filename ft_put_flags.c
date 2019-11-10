/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:48:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/10 20:04:42 by lhuang           ###   ########.fr       */
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

int		ft_precision(char *str, char converter, int i, int j, int *precision_exist, va_list p_copy)
{
	char *precision_str;//quand ya plusieurs .x ?
	int precision;

	precision = 0;
	precision_str = NULL;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '.')
			*precision_exist = 1;
		if (str[i] == '.' && ft_is_number(str[i + 1]))
		{
			i++;
			while (ft_is_number(str[i + j]))
				j++;
			precision_str = malloc(sizeof(char) * (j + 1));
			j = 0;
			i = i - j;
			while (ft_is_number(str[i]))
			{
				precision_str[j] = str[i];
				j++;
				i++;
			}
			precision_str[j] = '\0';
		}
		else if (str[i] == '.' && str[i + 1] == '*')
			precision = va_arg(p_copy, int);
		i++;
	}
	// if (precision)
	// 	return (precision);
	// return (ft_atoi_simple(precision_str));
	if (precision_str)
		return (ft_atoi_simple(precision_str));
	return (precision);
}

int		ft_width(char *str, char converter, va_list p_copy, int i)
{
	int width;//gere plusieurs * a la suite ?
	char *width_str;
	int j;

	j = 0;
	width = 0;
	width_str = NULL;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if(str[i] == '*' && ft_is_number(str[i + 1]))
		{
			i++;
			while (ft_is_number(str[i + j]))
				j++;
			width_str = malloc(sizeof(char) * (j + 1));
			j = 0;
			i = i - j;
			while (ft_is_number(str[i]))
			{
				width_str[j] = str[i];
				j++;
				i++;
			}
			width_str[j] = '\0';
			width = va_arg(p_copy, int);
		}
		else if (str[i] == '*')
			width = va_arg(p_copy, int);
		i++;
	}
	if (width_str)
		return (ft_atoi_simple(width_str));
	return (width);
	// if (width)
	// 	return (width);
	// return (ft_atoi_simple(width_str));
}
