/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:13:24 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/10 19:39:28 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// warning: data argument not used by format string
//todo : check nb argument (while loop ?)
//todo:  warning: data argument not used by format string [-Wformat-extra-args]
//todo: warning: more '%' conversions than data arguments [-Wformat]
//  ’-0.*’
// cspdiuxX%
// printf("%.0dd", 0);//output ==> rien
//va_arg = int, long, decimal, double, struct, union, pointeur, ou typedef de ses types
//todo: nombre negatif a prendre en compte
//todo: faudra tout free

int	ft_is_converter(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') ||
	(c == 'd') || (c == 'i') || (c == 'u') ||
	(c == 'x') || (c == 'X') || (c == '%'));
}

int ft_is_number(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_is_flag(char c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*') || ft_is_number(c));
}

void	ft_print(char converter, va_list p, t_cut *cut, int *size)
{
	//cas is convert
	//cas pas un convert yaura un warning mais affiche
	//ATTENTION * peut prendre un argument plus loin pas necessairement a cote de l'appel ????
	if (converter == 'c')
	{
		// ft_putchar(va_arg(p, int));
		*size = *size + ft_printchar(converter, p, cut);
	}
	else if (converter == 's')
	{
		*size = *size + ft_printstr(converter, p, cut);
		// ft_putstr(va_arg(p, char*));
	}
	else if (converter == 'p')
		ft_putaddress(va_arg(p, void*));
	else if (converter == 'd' || converter == 'i')
	{
		*size = *size + ft_printnbr(converter, p, cut);
		// ft_putnbr(va_arg(p, int));
	}
	else if (converter == 'u')
		ft_putnbr_unsigned(va_arg(p, unsigned int));
	else if (converter == 'x')
		ft_putnbr_base((unsigned long)va_arg(p, int),
		"0123456789abcdef", 16);
	else if (converter == 'X')
		ft_putnbr_base((unsigned long)va_arg(p, int),
		"0123456789ABCDEF", 16);
	else if(converter == '%' && cut->str_lenght > 1)
	{
		//les flags marchent ici
		*size = *size + ft_printchar(converter, p, cut);
		// *size = *size + 1;
	}
	// else if(cut->str_lenght > 1)//ne fait rien si ce n'est pas un bon converter
	// {
	// 	write(1, &converter, 1);
	// 	*size = *size + 1;
	// }
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	t_cut	*list_cuts;
	t_cut	*tmp;
	int		size;

	size = 0;
	list_cuts = NULL;
	list_cuts = ft_get_list_of_cut(str);
	tmp = list_cuts;
	// printf("new\n");
	// ft_print_cut_list(&list_cuts);
	va_start(p, str);
	while (list_cuts)
	{
		if (list_cuts->is_convert)
		{
			ft_print(list_cuts->str[list_cuts->str_lenght - 1],
			p, list_cuts, &size);
		}
		else
		{
			write(1, list_cuts->str, list_cuts->str_lenght);
			size += list_cuts->str_lenght;
		}
		list_cuts = list_cuts->next;
	}
	va_end(p);
	ft_free_list_cut(&tmp);
	return (size);
}

