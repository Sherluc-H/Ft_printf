/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cuts_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:48:27 by lhuang            #+#    #+#             */
/*   Updated: 2019/11/09 14:57:09 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_cut	*ft_newcut(char *str, int str_lenght, int is_convert)
{
	t_cut	*t_new;

	if (!(t_new = malloc(sizeof(*t_new))))
		return (NULL);
	t_new->str = str;
	t_new->str_lenght = str_lenght;
	t_new->is_convert = is_convert;
	t_new->next = NULL;
	return (t_new);
}

void	ft_add_back_cut(t_cut **cut, t_cut *new_cut)
{
	t_cut	*list_cut;

	if (cut != NULL && *cut == NULL)
	{
		*cut = new_cut;
		return ;
	}
	list_cut = *cut;
	if (list_cut != NULL)
	{
		while (list_cut->next)
			list_cut = list_cut->next;
		list_cut->next = new_cut;
	}
}

void	ft_print_cut_list(t_cut **cut)
{
	t_cut	*list_cut;

	if (cut && *cut)
	{
		list_cut = *cut;
		while (list_cut)
		{
			printf("->|str=%s,", list_cut->str);
			printf("len=%d,", list_cut->str_lenght);
			printf("is=%d|", list_cut->is_convert);
			list_cut = list_cut->next;
		}
	}
}

void	ft_free_list_cut(t_cut **cut)
{
	t_cut	*current;
	t_cut	*tmp;

	current = NULL;
	if (cut)
	{
		current = *cut;
	}
	if (current)
	{
		while (current)
		{
			tmp = current->next;
			free(current->str);
			current->str = NULL;
			free(current);
			current = tmp;
		}
		*cut = NULL;
	}
}
