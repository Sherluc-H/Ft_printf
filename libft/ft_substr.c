/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:15:28 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/13 15:46:59 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*p;
	unsigned int	s_size;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	s_size = i;
	i = 0;
	if (!(p = malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (i < (int)len && start < s_size && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
