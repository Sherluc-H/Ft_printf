/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:13:24 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/30 17:42:39 by lhuang           ###   ########.fr       */
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

int	ft_is_flag(char c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*'));
}

void	ft_print(char tc, va_list p, char *str)
{
	//cas is convert
	//cas pas un convert yaura un warning mais affiche
	//* peut prendre un argument plus loin pas necessairement a cote de l'appel
	if (tc == 'c')
		ft_putchar_fd(va_arg(p, int), 1);
	else if (tc == 's')
		ft_putstr_fd(va_arg(p, char*), 1);
	else if (tc == 'p')
		ft_putaddress(va_arg(p, void*));
	else if (tc == 'd' || tc == 'i')
		ft_putnbr_fd(va_arg(p, int), 1);
	else if (tc == 'u')
		ft_putnbr_unsigned(va_arg(p, unsigned int));
	else if (tc == 'x')
		ft_putnbr_base((unsigned long)va_arg(p, int),
		"0123456789abcdef", 16);
	else if (tc == 'X')
		ft_putnbr_base((unsigned long)va_arg(p, int),
		"0123456789ABCDEF", 16);
	else
		write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	va_list	p_copy;
	t_cut	*list_cuts;
	t_cut	*tmp;

	list_cuts = ft_get_list_of_cut(str);
	tmp = list_cuts;
	va_start(p, str);
	va_copy(p_copy, p);
	while (list_cuts)
	{
		if (list_cuts->is_convert)
			ft_print(list_cuts->str[list_cuts->str_lenght - 1],
			p_copy, list_cuts->str);
		else
			write(1, list_cuts->str, list_cuts->str_lenght);
		list_cuts = list_cuts->next;
	}
	va_end(p_copy);
	va_end(p);
	ft_free_list_cut(&tmp);
	return (1);
}

// int		ft_nb_of_conversions(const char *str)//compte le nb de str total conversion et non conversion inclus
// {
// 	int	i;
// 	int nb_of_strs;
// 	int bool_nv_mot;

// 	i = 0;
// 	nb_of_strs = 0;
// 	bool_nv_mot = 1;
// 	printf("==========%d", nb_of_strs);
// 	while (str[i])
// 	{
// 		while (str[i] != '%' && str[i])
// 		{
// 			if (bool_nv_mot)
// 			{
// 				nb_of_strs++;
// 				bool_nv_mot = 0;
// 			}
// 			i++;
// 		}
// 		bool_nv_mot = 1;
// 		if (str[i] == '%')
// 		{
// 			i++;
// 			printf("%c, i = %d", str[i], i);
// 			nb_of_strs++;
// 			while (ft_is_flag(str[i]) && str[i])
// 				i++;
// 			if (str[i] == '\0' || !(ft_is_converter(str[i])))
// 				return (0);
// 		}
// 		if(str[i])
// 			i++;
// 	}
// 	printf("==========%d\n", nb_of_strs);
// 	return (nb_of_strs + 1);
// }

// char	*ft_get_expected_types(const char *str)//fonction qui met dans un tableau les caracteres +1 apres le %
// {
// 	int		i;
// 	int		size;
// 	char	*p;

// 	i = 0;
// 	size = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%' && (ft_is_converter(str[i + 1]) ||
// 		ft_is_flag(str[i + 1])))
// 		{
// 			if (ft_is_flag(str[i + 1]))
// 			{
// 				while (ft_is_flag(str[i + 1]))
// 					i++;
// 				if (ft_is_converter(str[i + 1]))
// 					size++;
// 				i++;
// 			}
// 			else
// 			{
// 				size++;
// 				i++;
// 			}
// 			//printf("%c, %d", str[i], i);
// 		}
// 		i++;
// 	}
// 	//printf("|%d|\n", size);
// 	p = malloc(sizeof(char) * (size + 1));
// 	p[size] = '\0';
// 	i = 0;
// 	size = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%' && ft_is_converter(str[i + 1]))
// 		{
// 			p[size] = str[i + 1];
// 			//printf("%c, %d", str[i+1], i+1);
// 			i++;
// 			size++;
// 		}
// 		i++;
// 	}
// 	return (p);
// }

// int	ft_print(char c, char c2, char tc, va_list p)
// {
// 	if (c == '%' && tc && ft_is_converter(c2))
// 	{
// 		if (tc == 'c')
// 			ft_putchar_fd(va_arg(p, int), 1);
// 		else if (tc  == 's')
// 			ft_putstr_fd(va_arg(p, char*), 1);
// 		else if (tc == 'p')
// 			ft_putaddress(va_arg(p, void*));
// 		else if (tc == 'd' || tc == 'i')
// 			ft_putnbr_fd(va_arg(p, int), 1);
// 		else if (tc == 'u')
// 			ft_putnbr_unsigned(va_arg(p, unsigned int));
// 		else if (tc == 'x')
// 			ft_putnbr_base((unsigned long)va_arg(p, int),
// 			"0123456789abcdef", 16);
// 		else if (tc == 'X')
// 			ft_putnbr_base((unsigned long)va_arg(p, int),
// 			"0123456789ABCDEF", 16);
// 		else
// 			write(1, "%", 1);
// 		return (1);
// 	}
// 	write(1, &c, 1);
// 	return (0);
// }
