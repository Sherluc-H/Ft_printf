/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:58:14 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/17 14:42:44 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int				precision_exist;
	int				found_zero;
}					t_print_data;

t_cut				*ft_newcut(char *str, int str_lenght, int is_convert);
void				ft_add_back_cut(t_cut **cut, t_cut *new_cut);
int					ft_free_list_cut(t_cut **cut);
t_cut				*ft_get_list_of_cut(const char *str);
int					ft_strlenght(char *str);
void				ft_putchar(unsigned char c);
int					ft_putstr(char *s, int precision);
int					ft_atoi_simple(char *str);
void				ft_putnbr(int n);
void				ft_putnbr_base(unsigned long l, char const *table,
					int base);
int					ft_to_print_amount(int n);
int					ft_to_print_amount_base(unsigned long l, int base);
int					ft_precision(char *str, char converter, va_list p_copy,
					int i);
int					ft_precision_n(char *str, char converter, va_list p_copy,
					int i);
int					ft_width(char *str, t_print_data *t_p_data, va_list p_copy);
char				ft_found_minus(char *str, char converter);
char				ft_found_zero_for_char(char *str, char converter);
int					ft_get_flags_data(t_print_data *t_p_data, char converter,
					va_list p, t_cut *cut);
int					ft_print_back(t_print_data data, int n);
int					ft_print_front(t_print_data data, int n);
void				ft_prepare_long(t_print_data *data, unsigned long l, int *j,
					int base);
void				ft_add_zeros_nbr_back(t_print_data *data, int *size);
void				ft_add_zeros_nbr_front(t_print_data *data, int *size);
void				ft_add_space_nbr(t_print_data data, int *size, int *j,
					int max);
int					ft_print_back_base(t_print_data data, unsigned long l,
					char *table, int base);
int					ft_print_front_base(t_print_data data, unsigned long l,
					char *table, int base);
int					ft_printnbr(char converter, va_list p, t_cut *cut);
int					ft_printnbr_base(char converter, va_list p, t_cut *cut);
int					ft_print_back_char(t_print_data data, int n, char to_add);
int					ft_print_front_char(t_print_data data, int n, char to_add);
int					ft_printcharacteres(char converter, va_list p, t_cut *cut);
int					ft_print_back_str(t_print_data data, char *str,
					char to_add);
int					ft_print_front_str(t_print_data data, char *str,
					char to_add);
int					ft_is_converter(char c);
int					ft_is_number(char c);
int					ft_is_flag(char c);
int					ft_printf(const char *str, ...);

#endif
