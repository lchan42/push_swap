/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mvt_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:42:50 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 19:03:35 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_swap_b(t_stack **head, t_list **mvtbook)
{
	int		int_tmp;
	t_stack	*lst_tmp;

	if (!*head)
		return ;
	lst_tmp = (*head)->next;
	if (*head != lst_tmp)
	{
		int_tmp = (*head)->value;
		(*head)->value = lst_tmp->value;
		lst_tmp->value = int_tmp;
		int_tmp = (*head)->rank;
		(*head)->rank = lst_tmp->rank;
		lst_tmp->rank = int_tmp;
		int_tmp = (*head)->index;
		(*head)->index = lst_tmp->index;
		lst_tmp->index = int_tmp;
		ft_lstadd_back(mvtbook, ft_lstnew("sb"));
	}
}

void	ft_ps_push_b(t_stack **dst, t_stack **src, t_list **mvtbook)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		if (*src == (*src)->next)
			*src = NULL;
		else 
		{
			(*src)->previous->next = (*src)->next;
			(*src)->next->previous = (*src)->previous;
			*src = (*src)->next;
		}
		tmp->next = tmp;
		tmp->previous = tmp;
		if (*dst)
		{
			tmp->next = *dst;
			tmp->previous = (*dst)->previous;
			(*dst)->previous->next = tmp;
			(*dst)->previous = tmp;
		}
		*dst = tmp;
		ft_lstadd_back(mvtbook, ft_lstnew("pb"));
	}
}

void	ft_ps_rotate_b(t_stack **head, t_list **mvtbook)
{
	if (head && *head)
	{
		if ((*head)->next != *head)
		{
			*head = (*head)->next;
			ft_lstadd_back(mvtbook, ft_lstnew("rb"));
		}
	}
}

void	ft_ps_reverse_b(t_stack **head, t_list **mvtbook)
{
	if (head && *head)
	{
		if ((*head)->next != *head)
		{
			*head = (*head)->previous;
			ft_lstadd_back(mvtbook, ft_lstnew("rrb"));
		}
	}
}
