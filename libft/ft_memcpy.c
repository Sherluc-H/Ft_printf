/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:04:11 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/13 15:40:47 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (dst || src)
	{
		i = 0;
		a = dst;
		b = (void*)src;
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}
