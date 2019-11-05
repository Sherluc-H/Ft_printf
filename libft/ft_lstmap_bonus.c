/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:54:04 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/20 12:25:47 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_first(t_list *lst, void *(*f)(void *))
{
	t_list	*new_list;

	if (!(new_list = malloc(sizeof(*new_list))))
		return (NULL);
	if (lst->content)
	{
		new_list->content = (*f)(lst->content);
		new_list->next = NULL;
	}
	return (new_list);
}

static t_list	*ft_lstclear2(t_list **lst, void (*del)(void*))
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
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new_list;
	t_list	*previous;

	if (lst && f && del)
	{
		if (!(first = ft_first(lst, f)))
			return (NULL);
		new_list = first;
		while (lst->next)
		{
			previous = new_list;
			lst = lst->next;
			if (!(new_list = malloc(sizeof(*new_list))))
				return (ft_lstclear2(&first, del));
			if (lst->content)
				new_list->content = (*f)(lst->content);
			new_list->next = NULL;
			previous->next = new_list;
		}
		return (first);
	}
	else
		return (NULL);
}
