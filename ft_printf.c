/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:13:24 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/09 18:26:37 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

	// warning: data argument not used by format string
	//todo : check nb argument (while loop ?)
//todo:  warning: data argument not used by format string [-Wformat-extra-args]
//todo: warning: more '%' conversions than data arguments [-Wformat]
//* specification de largeur
//. specification de precision 
//- decale a gauche
//0 rajoute des 0 quand nombre pas assez grand
//  ’-0.*’
// cspdiuxX%
// printf("%.0dd", 0);//output ==> rien
//va_arg = int, long, decimal, double, struct, union, pointeur, ou typedef de ses types
	//todo: nombre negatif a prendre en compte
	//todo: void* pour utiliser pointeur sur fonction ?
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

void	ft_print(char converter, va_list p_copy, t_cut *cut, int *size)
{
	//cas is convert
	//cas pas un convert yaura un warning mais affiche
	//* peut prendre un argument plus loin pas necessairement a cote de l'appel
	if (converter == 'c')
		ft_putchar(va_arg(p_copy, int));
	else if (converter == 's')
		ft_putstr(va_arg(p_copy, char*));
	else if (converter == 'p')
		ft_putaddress(va_arg(p_copy, void*));
	else if (converter == 'd' || converter == 'i')
	{
		*size = *size + ft_printnbr(converter, p_copy, cut);
		// ft_putnbr(va_arg(p_copy, int));
	}
	else if (converter == 'u')
		ft_putnbr_unsigned(va_arg(p_copy, unsigned int));
	else if (converter == 'x')
		ft_putnbr_base((unsigned long)va_arg(p_copy, int),
		"0123456789abcdef", 16);
	else if (converter == 'X')
		ft_putnbr_base((unsigned long)va_arg(p_copy, int),
		"0123456789ABCDEF", 16);
	else if(converter == '%' && cut->str_lenght == 2)
	{
		write(1, "%", 1);
		*size = *size + 1;
	}
	else if(cut->str_lenght > 1)
	{
		write(1, &converter, 1);
		*size = *size + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	va_list	p_copy;
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
	va_copy(p_copy, p);
	while (list_cuts)
	{
		if (list_cuts->is_convert)
		{
			ft_print(list_cuts->str[list_cuts->str_lenght - 1],
			p_copy, list_cuts, &size);
		}
		else
		{
			write(1, list_cuts->str, list_cuts->str_lenght);
			size += list_cuts->str_lenght;
		}
		list_cuts = list_cuts->next;
	}
	va_end(p_copy);
	va_end(p);
	ft_free_list_cut(&tmp);
	return (size);
}

