/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mvt_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:42:50 by lchan             #+#    #+#             */
/*   Updated: 2022/04/12 23:21:17 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back_mvt(t_stack **a, t_stack **b, t_list **m, char *mvt)
{
	t_list	*tmp;

	tmp = ft_lstnew(mvt);
	if (!tmp)
	{
		ps_free_env(a, b, m);
		exit(MVTBOOK_ERROR);
	}
	ft_lstadd_back(m, tmp);
}

void	ft_ps_swap_a(t_stack **a, t_list **m)
{
	int		int_tmp;
	t_stack	*lst_tmp;
	
	if (!*a)
		return;
	lst_tmp = (*a)->next;
	if (*a != lst_tmp)
	{
		int_tmp = (*a)->value;
		(*a)->value = lst_tmp->value;
		lst_tmp->value = int_tmp;
		int_tmp = (*a)->rank;
		(*a)->rank = lst_tmp->rank;
		lst_tmp->rank = int_tmp;
		int_tmp = (*a)->index;
		(*a)->index = lst_tmp->index;
		lst_tmp->index = int_tmp;
		ft_lstadd_back(m, ft_lstnew("sa"));
	}
}
/*********************************************************
 * the if condition is checking 
 * 		if stack empty AND IF
 * 		there is at least 2 elements in the circular list
 * *******************************************************/

void	ft_ps_push_a(t_stack **dst, t_stack **src, t_list **m)
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
		ps_lstadd_back_mvt(dst, src, m, "pa");
		//ft_lstadd_back(m, ft_lstnew("pa"));
	}
}

void	ft_ps_rotate_a(t_stack **a, t_list **m) //need more check
{
	if (a && *a)
	{
		if ((*a)->next != *a)
		{
			*a = (*a)->next;
			ft_lstadd_back(m, ft_lstnew("ra"));
		}
	}
}

void	ft_ps_reverse_a(t_stack **a, t_list **m)
{
	if (a && *a && (*a)->next != *a)
	{
		*a = (*a)->previous;
		ft_lstadd_back(m, ft_lstnew("rra"));
	}
}
