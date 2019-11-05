/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:06:39 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/19 19:37:21 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (alst != NULL && *alst == NULL)
	{
		*alst = new;
		return ;
	}
	if (alst)
	{
		lst = *alst;
		if (lst != NULL)
		{
			while (lst->next)
				lst = lst->next;
			lst->next = new;
		}
	}
}
