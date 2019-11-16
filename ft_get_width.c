/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:45:30 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 17:56:27 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width_number(char *str, int *i, int *width)
{
	int		j;
	int		tmp;
	char	*width_str;

	j = 0;
	while (ft_is_number(str[*i + j]))
		j++;
	if (!(width_str = malloc(sizeof(char) * (j + 1))))
		return (-1);
	j = 0;
	while (ft_is_number(str[*i]))
	{
		width_str[j] = str[*i];
		j++;
		*i = *i + 1;
	}
	width_str[j] = '\0';
	if ((tmp = ft_atoi_simple(width_str)) != 0)
		*width = tmp;
	return (1);
}

int		ft_asterix_width(char *str, va_list p_copy, int *width, int i)
{
	int found_minus;

	found_minus = 0;
	if (str[i] == '*' && str[i - 1] != '.')// if (str[i] == '*')
	{
		*width = va_arg(p_copy, int);
		if (*width < 0)//si width < 0 il faut donner la valeur positif
		{
			*width = -*width;//le - sera vu comme un flag -
			found_minus = 1;
		}
	}
	if (str[i] == '*' && str[i - 1] == '.')
		va_arg(p_copy, int);
	if (found_minus)
		return (1);
	return (0);
}

int		ft_width_check_dot(char *str, int *width, int *i)
{
	if (ft_is_number(str[*i]) && str[*i - 1] != '*' && str[*i - 1] != '.')
	{
		if ((ft_width_number(str, i, width)) == -1)
			return (-1);
	}
	if (str[*i] == '.')
	{
		*i = *i + 1;
		while (ft_is_number(str[*i]))
			*i = *i + 1;
	}
	return (1);
}

int		ft_width(char *str, t_print_data *t_p_data, va_list p_copy)
{
	int width;
	int i;

	i = 0;
	width = 0;
	if (t_p_data->converter == '%')
		i++;
	while (str[i] && str[i] != t_p_data->converter)
	{
		if ((ft_width_check_dot(str, &width, &i)) == -1)
			return (-1);
		if (ft_asterix_width(str, p_copy, &width, i) == 1)
			t_p_data->found_minus = 1;
		if (str[i] == '*' && ft_is_number(str[i + 1]))
		{
			i++;
			if ((ft_width_number(str, &i, &width)) == -1)
				return (-1);
			i--;
		}
		i++;
	}
	return (width);
}
