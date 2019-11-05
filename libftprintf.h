/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:36:31 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/30 17:42:33 by lhuang           ###   ########.fr       */
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

t_cut				*ft_newcut(char *str, int str_lenght, int is_convert);
void				ft_add_back_cut(t_cut **cut, t_cut *new_cut);
void				ft_print_cut_list(t_cut **cut);
void				ft_free_list_cut(t_cut **cut);
int					ft_create_cut_convert(t_cut **cut, const char *str,
					int i, int j);
int					ft_create_cut_non_convert(t_cut **cut, const char *str,
					int i, int j);
t_cut				*ft_get_list_of_cut(const char *str);
void				ft_putnbr_base(unsigned long l, char const *table,
					int base);
void				ft_putnbr_unsigned(unsigned int n);
void				ft_putaddress(void *p);
int					ft_is_converter(char c);
int					ft_is_flag(char c);
void				ft_print(char tc, va_list p, char *str);
int					ft_printf(const char *str, ...);

#endif
