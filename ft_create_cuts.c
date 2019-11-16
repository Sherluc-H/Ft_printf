/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cuts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:43:24 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/16 17:56:36 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_create_cut_convert(t_cut **cut, const char *str, int i, int j)
{
	char	*new_str;
	int		k;

	k = 0;
	if (!(new_str = malloc(sizeof(char) * (j + 1))))
		return (0);
	while (k < j)
	{
		new_str[k] = str[i - j + k];
		k++;
	}
	new_str[j] = '\0';
	ft_add_back_cut(cut, ft_newcut(new_str, j, 1));
	return (1);
}

int		ft_create_cut_non_convert(t_cut **cut, const char *str, int i, int j)
{
	char	*new_str;
	int		k;

	k = 0;
	if (!(new_str = malloc(sizeof(char) * (j + 1))))
		return (0);
	while (k < j)
	{
		new_str[k] = str[i - j + k];
		k++;
	}
	new_str[j] = '\0';
	ft_add_back_cut(cut, ft_newcut(new_str, j, 0));
	return (1);
}

void	ft_loop_non_converter(const char *str, int *i, int *j, int *bool_nv_mot)
{
	while (str[*i] != '%' && str[*i])
	{
		if (*bool_nv_mot)
			*bool_nv_mot = 0;
		*i = *i + 1;
		*j = *j + 1;
	}
}

void	ft_loop_converter(const char *str, int *i, int *j)
{
	if (str[*i] == '%')
	{
		if (str[*i + 1])//si cest que 1 % a la fin
		{
			*i = *i + 1;
			*j = *j + 1;
		}
		while (ft_is_flag(str[*i]) && str[*i])
		{
			*i = *i + 1;
			*j = *j + 1;
		}
		if (str[*i])
		{
			*i = *i + 1;
			*j = *j + 1;
		}//va apres le \0 ? sinon ?
	}
}

t_cut	*ft_get_list_of_cut(const char *str)//compte le nb de str total conversion et non conversion inclus
{
	int		i;
	int		j;
	int		bool_nv_mot;
	t_cut	*first;

	i = 0;
	first = NULL;
	bool_nv_mot = 1;
	while (str[i])
	{
		j = 0;
		ft_loop_non_converter(str, &i, &j, &bool_nv_mot);
		if (j != 0)
			ft_create_cut_non_convert(&first, str, i, j);
		j = 0;
		bool_nv_mot = 1;
		ft_loop_converter(str, &i, &j);
		if (j != 0)
			ft_create_cut_convert(&first, str, i, j);
	}
	return (first);
}
