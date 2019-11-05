/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:16:01 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/23 11:05:42 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_separator(int i, char const *str, char c)
{
	if (str[i] == c)
		return (1);
	return (0);
}

static int	ft_nb_of_strs(char const *str, char c)
{
	int i;
	int nb_of_strs;
	int bool_nv_mot;

	i = 0;
	nb_of_strs = 0;
	bool_nv_mot = 1;
	while (str[i] != '\0')
	{
		while (!ft_is_separator(i, str, c) && str[i] != '\0')
		{
			if (bool_nv_mot)
			{
				nb_of_strs++;
				bool_nv_mot = 0;
			}
			i++;
		}
		while (ft_is_separator(i, str, c) && str[i] != '\0')
		{
			bool_nv_mot = 1;
			i++;
		}
	}
	return (nb_of_strs + 1);
}

static char	*ft_get_str(char const *str, int *i, char c)
{
	int		k;
	int		lengh_of_str;
	char	*str_assist;

	k = 0;
	lengh_of_str = 0;
	str_assist = NULL;
	while (!ft_is_separator(*i, str, c) && str[*i] != '\0')
	{
		lengh_of_str++;
		*i = *i + 1;
	}
	if (lengh_of_str != 0)
	{
		if (!(str_assist = malloc(sizeof(char) * lengh_of_str + 1)))
			return (NULL);
		while (k < lengh_of_str)
		{
			str_assist[k] = str[*i - lengh_of_str + k];
			k++;
		}
		str_assist[k] = '\0';
	}
	return (str_assist);
}

static char	**ft_clean_strs(char **p, int num_str)
{
	while (num_str >= 0)
	{
		free(p[num_str]);
		num_str--;
	}
	free(p);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		nb_of_strs;
	char	**p;
	int		num_str;
	char	*new_str;

	p = NULL;
	if (!s)
		return (p);
	i = 0;
	num_str = 0;
	nb_of_strs = ft_nb_of_strs(s, c);
	if (!(p = malloc(sizeof(*p) * nb_of_strs)))
		return (NULL);
	while (s[i] != '\0' && num_str < nb_of_strs - 1)
	{
		while (ft_is_separator(i, s, c))
			i++;
		if (!(new_str = ft_get_str(s, &i, c)))
			return (ft_clean_strs(p, num_str - 1));
		p[num_str] = new_str;
		num_str++;
	}
	p[nb_of_strs - 1] = 0;
	return (p);
}
