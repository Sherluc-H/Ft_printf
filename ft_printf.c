/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:13:24 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:42:57 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_conv(char converter, va_list p, t_cut *cut)
{
	if (converter == 'c' || converter == 's' ||
		(converter == '%' && cut->str_lenght > 1))
		return (ft_printcharacteres(converter, p, cut));
	else if (converter == 'p' || converter == 'u' ||
			converter == 'x' || converter == 'X')
		return (ft_printnbr_base(converter, p, cut));
	else if (converter == 'd' || converter == 'i')
		return (ft_printnbr(converter, p, cut));
	else
	{
		write(1, &converter, 1);
		return (1);
	}
}

static int	ft_start_print(t_cut *list_cuts, va_list p)
{
	int size;
	int add;

	add = 0;
	size = 0;
	while (list_cuts)
	{
		if (list_cuts->is_convert)
		{
			if ((add = ft_print_conv(
				list_cuts->str[list_cuts->str_lenght - 1], p, list_cuts)) != -1)
				size += add;
			else
				return (-1);
		}
		else
		{
			write(1, list_cuts->str, list_cuts->str_lenght);
			size += list_cuts->str_lenght;
		}
		list_cuts = list_cuts->next;
	}
	return (size);
}

int			ft_printf(const char *str, ...)
{
	va_list	p;
	t_cut	*list_cuts;
	t_cut	*tmp;
	int		size;
	int		add;

	size = 0;
	add = 0;
	list_cuts = NULL;
	list_cuts = ft_get_list_of_cut(str);
	tmp = list_cuts;
	va_start(p, str);
	if ((size = ft_start_print(list_cuts, p)) == -1)
		return (ft_free_list_cut(&tmp));
	va_end(p);
	ft_free_list_cut(&tmp);
	return (size);
}
