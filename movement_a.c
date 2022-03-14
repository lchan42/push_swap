/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:42:50 by lchan             #+#    #+#             */
/*   Updated: 2022/03/14 20:00:37 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_ps_mvtexecutor(t_stack **stack_a, t_stack **stack_b, t_list movebook, char *mvt)
{
	if (mvt == "sa")
		swap(stack_a);
	if (mvt == "sb")
		swap(stack_a);
	if (mvt == "pa")
		push(stack_a, stack_b);
	if (mvt == "pb")
	if (mvt == "ra")
	if (mvt == "rb")
	if (mvt == "rra")
	if (mvt == "rrb")
	if (mvt == "rrr")
	ft_lstadd_back(&movebook, ft_lstnew(move));
}//not sure that a forest of if is needed;
*/
void	ft_ps_swap_a(t_stack **head, t_list **mvtbook)
{
	int		int_tmp;
	t_stack	*lst_tmp;

	if (*head && *head != lst_tmp)
	{
		lst_tmp = (*head)->next;
		int_tmp = (*head)->value;
		(*head)->value = lst_tmp->value;
		lst_tmp->value = int_tmp;
		int_tmp = (*head)->rank;
		(*head)->rank = lst_tmp->rank;
		lst_tmp->rank = int_tmp;
		int_tmp = (*head)->index;
		(*head)->index = lst_tmp->index;
		lst_tmp->index = int_tmp;
		ft_lstadd_back(mvtbook, ft_lstnew("sa"));
	}
}
/**************************************************
 * the if condition is checking if 
 * 		stack is empty AND IF
 * 		there is at least 2 elements in the circular list

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.
*/

void	ft_ps_push_a(t_stack **dst, t_stack **src, t_list **mvtbook)
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
		ft_lstadd_back(mvtbook, ft_lstnew("pa"));
	}
}

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/

void	ft_ps_rotate_a(t_stack **head, t_list **mvtbook) //need more check
{
	if (head && *head)
	{
		*head = (*head)->next;
		ft_lstadd_back(mvtbook, ft_lstnew("ra"));
	}
}
/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.
*/


void	ft_ps_reverse_a(t_stack **head, t_list **mvtbook)
{
	if (head && *head)
	{
		*head = (*head)->previous;
		ft_lstadd_back(mvtbook, ft_lstnew("rra"));
	}
}
/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/
