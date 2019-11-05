/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:54:04 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/13 18:01:26 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen3(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_size;
	char	*p;

	i = 0;
	if (s)
	{
		s_size = ft_strlen3(s);
		if (!(p = malloc(s_size * sizeof(char) + 1)))
			return (NULL);
		while (i < s_size)
		{
			if (f)
				p[i] = (*f)(i, s[i]);
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
