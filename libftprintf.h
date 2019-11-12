/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:36:31 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/11 19:15:15 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_cut
{
	char			*str;
	int				str_lenght;
	int				is_convert;
	struct s_cut	*next;
}					t_cut;

//ft_cuts_lists
t_cut				*ft_newcut(char *str, int str_lenght, int is_convert);
void				ft_add_back_cut(t_cut **cut, t_cut *new_cut);
void				ft_print_cut_list(t_cut **cut);
void				ft_free_list_cut(t_cut **cut);

//ft_create_cuts
int					ft_create_cut_convert(t_cut **cut, const char *str,
					int i, int j);
int					ft_create_cut_non_convert(t_cut **cut, const char *str,
					int i, int j);
t_cut				*ft_get_list_of_cut(const char *str);

//ft_put_utils
int					ft_strlenght(char *str);
// void				ft_putchar(char c);
void	ft_putchar(unsigned char c);

void				ft_putnbr(int n);
int					ft_putstr(char *s);
void				ft_putnbr_base(unsigned long l, char const *table,
					int base);
void				ft_putnbr_unsigned(unsigned int n);
// void				ft_putaddress(void *p);
int					ft_atoi_simple(char *str);
int					ft_to_print_amount(int n);
int					ft_to_print_amount_base(unsigned long l, int base);

//ft_put_flags
char				ft_found_minus(char *str, char converter);
char				ft_found_zero_for_char(char *str, char converter);
int					ft_precision(char *str, char converter, int i, int j, va_list p_copy);
int					ft_width(char *str, char converter, va_list p_copy, int i);

//ft_put_cuts
int					ft_print_back(int *size, int precision, int width, int n, int dot);
int					ft_print_front(int *size, int precision, int width, int n, int dot);
int					ft_printnbr(char converter, va_list p_copy, t_cut *cut);
int					ft_print_back_char(int *size, int width, int n, char to_add);
int					ft_print_front_char(int *size, int width, int n, char to_add);
int					ft_printchar(char converter, va_list p_copy, t_cut *cut);
int					ft_printstr(char converter, va_list p_copy, t_cut *cut);

//ft_put_cuts_nbr
int				ft_putaddress(char converter, va_list p, t_cut *cut);
int		ft_print_back_base(int *size, int precision, int width, unsigned long l, int dot, int is_address);
int		ft_print_front_base(int *size, int precision, int width, unsigned long l, int dot, int is_address);
int		ft_printnbr_base(char converter, va_list p_copy, t_cut *cut);


//ft_printf
int					ft_is_converter(char c);
int 				ft_is_number(char c);
int					ft_is_flag(char c);
int					ft_print(char converter, va_list p, t_cut *cut);
int					ft_printf(const char *str, ...);

#endif
