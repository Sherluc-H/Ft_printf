/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cuts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:43:24 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/09 15:18:39 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		while (str[i] != '%' && str[i])
		{
			if (bool_nv_mot)
				bool_nv_mot = 0;
			i++;
			j++;
		}
		if (j != 0)
			ft_create_cut_non_convert(&first, str, i, j);
		j = 0;
		bool_nv_mot = 1;
		if (str[i] == '%')
		{
			if(str[i + 1])//si cest que 1 % a la fin
			{
				i++;
				j++;
			}
			while (ft_is_flag(str[i]) && str[i])
			{
				i++;
				j++;
			}
			j++;//va apres le \0 ?
			i++;
		}
		if (j != 0)
			ft_create_cut_convert(&first, str, i, j);
	}
	return (first);
}
