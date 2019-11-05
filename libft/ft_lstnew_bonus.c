/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:30:52 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 12:26:27 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_new;

	if (!(t_new = malloc(sizeof(*t_new))))
		return (NULL);
	t_new->content = content;
	t_new->next = NULL;
	return (t_new);
}
