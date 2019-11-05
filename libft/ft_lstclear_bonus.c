/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:31:47 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/23 11:05:30 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	current = NULL;
	if (lst)
		current = *lst;
	if (current && del)
	{
		while (current)
		{
			tmp = current->next;
			(*del)(current->content);
			current->content = NULL;
			free(current);
			current = tmp;
		}
		*lst = NULL;
	}
}
