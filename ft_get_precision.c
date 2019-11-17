/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:58:10 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:02:52 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_number_after_dot(char *str, int *i, int *precision)
{
	int		j;
	char	*precision_str;

	j = 0;
	while (ft_is_number(str[*i + j]))
		j++;
	if (!(precision_str = malloc(sizeof(char) * (j + 1))))
		return (-1);
	j = 0;
	while (ft_is_number(str[*i]))
	{
		precision_str[j] = str[*i];
		j++;
		*i = *i + 1;
	}
	precision_str[j] = '\0';
	*precision = ft_atoi_simple(precision_str);
	return (1);
}

static void	ft_asterix_after_dot(char *str, int *i, int *precision,
			va_list p_copy)
{
	int new_precision;

	new_precision = 0;
	if (str[*i] == '*')
	{
		new_precision = va_arg(p_copy, int);
		if (new_precision >= 0)
			*precision = new_precision;
		*i = *i + 1;
		while (str[*i] == '*')
		{
			va_arg(p_copy, int);
			*i = *i + 1;
		}
	}
	else
		*precision = 0;
}

int			ft_precision(char *str, char converter, va_list p_copy, int i)
{
	int precision;

	precision = 0;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '*')
			va_arg(p_copy, int);
		if (str[i] == '.' && ft_is_number(str[i + 1]))
		{
			i++;
			if ((ft_number_after_dot(str, &i, &precision)) == -1)
				return (-1);
			i--;
		}
		else if (str[i] == '.')
		{
			i++;
			ft_asterix_after_dot(str, &i, &precision, p_copy);
			i--;
		}
		i++;
	}
	return (precision);
}

static void	ft_asterix_after_dot_negatif(char *str, int *i,
		int *precision, va_list p_copy)
{
	int new_precision;

	new_precision = 0;
	if (str[*i] == '*')
	{
		new_precision = va_arg(p_copy, int);
		if (new_precision >= 0)
			*precision = new_precision;
		if (new_precision < 0)
			*precision = -2;
		*i = *i + 1;
		while (str[*i] == '*')
		{
			va_arg(p_copy, int);
			*i = *i + 1;
		}
	}
	else
		*precision = 0;
}

int			ft_precision_n(char *str, char converter, va_list p_copy, int i)
{
	int precision;

	precision = 0;
	if (converter == '%')
		i++;
	while (str[i] && str[i] != converter)
	{
		if (str[i] == '*')
			va_arg(p_copy, int);
		if (str[i] == '.' && ft_is_number(str[i + 1]))
		{
			i++;
			if ((ft_number_after_dot(str, &i, &precision)) == -1)
				return (-1);
			i--;
		}
		else if (str[i] == '.')
		{
			i++;
			ft_asterix_after_dot_negatif(str, &i, &precision, p_copy);
			i--;
		}
		i++;
	}
	return (precision);
}
