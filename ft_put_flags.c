/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:48:03 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:26:29 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_found_minus(char *str, char converter)
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

char		ft_found_zero_for_char(char *str, char converter)
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

static int	ft_get_flags_data_first(t_print_data *t_p_data,
			char converter, va_list p, t_cut *cut)
{
	va_list p_copy;

	t_p_data->converter = converter;
	t_p_data->is_address = converter == 'p' ? 1 : 0;
	va_copy(p_copy, p);
	t_p_data->found_minus = ft_found_minus(cut->str, converter);
	t_p_data->found_zero = ft_found_zero_for_char(cut->str, converter);
	if ((t_p_data->precision = ft_precision(cut->str,
								converter, p_copy, 0)) == -1)
		return (-1);
	va_copy(p_copy, p);
	if ((t_p_data->width = ft_width(cut->str, t_p_data, p_copy)) == -1)
		return (-1);
	va_end(p_copy);
	return (1);
}

int			ft_get_flags_data(t_print_data *tp, char co, va_list p, t_cut *cut)
{
	va_list	p_copy;
	int		i;

	i = 0;
	if ((ft_get_flags_data_first(tp, co, p, cut)) == -1)
		return (-1);
	tp->dot = 0;
	while ((cut->str)[i] != co)
	{
		if ((cut->str)[i] == '.')
			tp->dot = 1;
		i++;
	}
	va_copy(p_copy, p);
	if (tp->dot && ((ft_precision_n(cut->str, co, p_copy, 0)) == -2))
		tp->dot = 0;
	va_end(p_copy);
	i = 0;
	while ((cut->str)[i] != co)
	{
		if ((cut->str)[i] == '*')
			va_arg(p, int);
		i++;
	}
	return (1);
}
