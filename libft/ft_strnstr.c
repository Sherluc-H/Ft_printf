/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:18:04 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 12:31:11 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		needle_size;

	i = 0;
	if ((needle_size = ft_strlen1(needle)) == 0)
		return ((char*)haystack);
	while (i < len && haystack[i])
	{
		if (i + needle_size <= len && haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && haystack[i + j] == needle[j] &&
			haystack[i + j] && needle[j])
				j++;
			if (j == needle_size)
				return ((char*)&haystack[i + j - needle_size]);
		}
		i++;
	}
	return (NULL);
}
