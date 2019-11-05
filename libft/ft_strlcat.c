/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:06:17 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 17:48:28 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen6(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t dst_size2;
	size_t src_size;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (dstsize + ft_strlen6(src));
	while (dst[i] && i < dstsize)
		i++;
	dst_size2 = i;
	i = 0;
	while (src[j] && dst_size2 + j < dstsize - 1 && dstsize != 0)
	{
		dst[dst_size2 + j] = src[j];
		j++;
	}
	src_size = ft_strlen6(src);
	if (dstsize <= dst_size2)
	{
		return (src_size + dstsize);
	}
	dst[dst_size2 + j] = '\0';
	return (src_size + dst_size2);
}
