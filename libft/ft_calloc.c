/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:16:10 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/25 13:33:31 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset1(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*a;

	i = 0;
	a = b;
	while (i < (int)len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void		*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*p;

	i = 0;
	if ((p = malloc(count * size)))
		return (ft_memset1(p, '\0', count * size));
	else
		return (NULL);
}
