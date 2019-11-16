/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:36:31 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 16:40:27 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_cut
{
	char			*str;
	int				str_lenght;
	int				is_convert;
	struct s_cut	*next;
}					t_cut;

typedef struct		s_print_data
{
	int				precision;
	int				width;
	char			converter;
	int				found_minus;
	int				is_address;
	int				dot;
	int				found_zero;
}					t_print_data;

//ft_cuts_lists
t_cut				*ft_newcut(char *str, int str_lenght, int is_convert);
void				ft_add_back_cut(t_cut **cut, t_cut *new_cut);
void				ft_print_cut_list(t_cut **cut);
int				ft_free_list_cut(t_cut **cut);

//ft_create_cuts
int					ft_create_cut_convert(t_cut **cut, const char *str,
					int i, int j);
int					ft_create_cut_non_convert(t_cut **cut, const char *str,
					int i, int j);
t_cut				*ft_get_list_of_cut(const char *str);

//ft_put_utils
int					ft_strlenght(char *str);
void				ft_putchar(unsigned char c);
void				ft_putnbr(int n);
int					ft_putstr(char *s, int precision);
void				ft_putnbr_base(unsigned long l, char const *table,
					int base);
int					ft_atoi_simple(char *str);
int					ft_to_print_amount(int n);
int					ft_to_print_amount_base(unsigned long l, int base);

//ft_put_flags
char				ft_found_minus(char *str, char converter);
char				ft_found_zero_for_char(char *str, char converter);
int		ft_precision(char *str, char converter, va_list p_copy, int i);
int					ft_width(char *str, t_print_data *t_p_data, va_list p_copy);
int					ft_get_flags_data_first(t_print_data *t_p_data, char converter, va_list p, t_cut *cut);
int					ft_get_flags_data(t_print_data *t_p_data, char converter, va_list p, t_cut *cut);
int		ft_precision_n(char *str, char converter, va_list p_copy, int i);

//ft_put_cuts
int					ft_print_back(t_print_data data, int n);
int					ft_print_front(t_print_data data, int n);
int					ft_printnbr(char converter, va_list p_copy, t_cut *cut);
int					ft_print_back_char(t_print_data data, int n, char to_add);
int					ft_print_front_char(t_print_data data, int n, char to_add);
int					ft_print_back_str(t_print_data data, char *str, char to_add);
int					ft_print_front_str(t_print_data data, char *str, char to_add);
int					ft_printcharacteres(char converter, va_list p_copy, t_cut *cut);
// int					ft_printstr(char converter, va_list p_copy, t_cut *cut);

//ft_put_cuts_nbr
int					ft_print_back_base(t_print_data data, unsigned long l, char *table, int base);
int					ft_print_front_base(t_print_data data, unsigned long l, char *table, int base);
int					ft_print_base(t_print_data t_p_data, unsigned long l, char *table);
int					ft_printnbr_base(char converter, va_list p, t_cut *cut);


//ft_printf
int					ft_is_converter(char c);
int 				ft_is_number(char c);
int					ft_is_flag(char c);
int					ft_print(char converter, va_list p, t_cut *cut);
int					ft_printf(const char *str, ...);

#endif
