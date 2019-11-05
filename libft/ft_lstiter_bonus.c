/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:43:05 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 12:25:19 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst->next)
		{
			if (lst->content)
				(*f)(lst->content);
			lst = lst->next;
		}
		if (lst->content)
		{
			(*f)(lst->content);
		}
	}
}
