/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:38:29 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 17:47:49 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_merge(char const *s1, char const *s2, int s1_size, int s2_size)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(p = malloc(sizeof(char) * (s1_size + s2_size) + 1)))
		return (NULL);
	while (i < s1_size)
	{
		p[i] = s1[i];
		i++;
	}
	while (j < s2_size)
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;

	if (s1 && s2)
	{
		s1_size = ft_strlen2(s1);
		s2_size = ft_strlen2(s2);
		return (ft_merge(s1, s2, s1_size, s2_size));
	}
	return (NULL);
}
