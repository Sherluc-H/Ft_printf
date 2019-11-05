/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cuts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:43:24 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/30 17:44:09 by lhuang           ###   ########.fr       */
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
			i++;
			j++;
			while (ft_is_flag(str[i]) && str[i])
			{
				i++;
				j++;
			}
			// if (str[i] == '\0' || !(ft_is_converter(str[i])))
			// 	return (0);
			// else
			//pour afficher les trucs meme si cest pas un convert, le vrai donne un warning mais affiche quand meme
			j++;
			i++;
		}
		if (j != 0)
			ft_create_cut_convert(&first, str, i, j);
		// if(str[i])
		// 	i++;
	}
	ft_print_cut_list(&first);
	return (first);
}
