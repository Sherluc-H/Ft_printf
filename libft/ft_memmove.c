/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:45:34 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 12:28:25 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;
	int				overlap;

	i = 0;
	a = dst;
	b = (void*)src;
	overlap = 0;
	if (len == 0 || !(dst || src) || src == dst)
		return (dst);
	if (&a[0] > &b[0])
	{
		if (&a[0] <= &b[len - 1])
			overlap = 1;
	}
	while (i < len)
	{
		if (overlap)
			a[len - i - 1] = b[len - i - 1];
		else
			a[i] = b[i];
		i++;
	}
	return (dst);
}
