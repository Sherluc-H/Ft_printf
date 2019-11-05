/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:07:55 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/23 11:05:49 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen5(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int		ft_jusqua_pos(const char *s1, const char *set,
				int found, int n)
{
	int i;
	int j;
	int set_length;

	set_length = ft_strlen5(set);
	i = 0;
	j = 0;
	while (s1[i] && found)
	{
		while (set[j] && found)
		{
			if (s1[i] != set[j])
				n++;
			j++;
		}
		if (n == set_length)
			found = 0;
		j = 0;
		n = 0;
		i++;
	}
	if (found)
		return (i);
	return (i - 1);
}

static int		ft_jusqua_pos_back(const char *s1, const char *set,
				int found, int s1_length)
{
	int j;
	int k;
	int n;
	int set_length;

	set_length = ft_strlen5(set);
	j = 0;
	k = s1_length - 1;
	while (k >= 0 && found)
	{
		j = 0;
		n = 0;
		while (set[j] && found)
		{
			if (s1[k] != set[j])
				n++;
			j++;
		}
		if (n == set_length)
			found = 0;
		k--;
	}
	if (found)
		return (0);
	return (k + 1);
}

static char		*ft_createstr(char const *s1, int start, int end)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = malloc((end - start) * sizeof(char) + 1)))
		return (NULL);
	while (i < end - start)
	{
		p[i] = s1[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		s1_length;

	if (s1 && set)
	{
		s1_length = ft_strlen5(s1);
		start = ft_jusqua_pos(s1, set, 1, 0);
		if (start == s1_length)
			end = start;
		else
			end = ft_jusqua_pos_back(s1, set, 1, s1_length) + 1;
		return (ft_createstr(s1, start, end));
	}
	return (NULL);
}
