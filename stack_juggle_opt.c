/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/24 17:49:52 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ps_min_index(t_stack *head)
{
	t_stack	*tmp;
	int		min;

	tmp = head;
	min = head->index;
	while (tmp->next != head)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp ->next;
	}
	return (min);
}

int		ft_ps_max_index(t_stack *head)
{
	t_stack	*tmp;
	int		max;

	tmp = head;
	max = head->index;
	while (tmp->next != head)
	{
		if (tmp->index < max)
			max = tmp->index;
		tmp = tmp ->next;
	}
	return (max);
}
/*
void	ft_ps_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	ft_ps_push_b(stack_b, stack_a, mvtbook);
	if ((*stack_b)->rank <= pivot)
	{
		(*stack_b)->index = pivot - 1;
		if ((*stack_b)->next != *stack_b)
			ft_ps_rotate_b(stack_b, mvtbook);
	}
	else
		(*stack_b)->index = pivot + 1;
} //(b = destination)
*//*
void	ft_ps_pushorganise_bs(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	ft_ps_push_b(stack_b, stack_a, mvtbook);
	if ((*stack_b)->rank <= pivot)
		(*stack_b)->index = pivot - 1;
	else
	{
		(*stack_b)->index = pivot + 1;
		if ((*stack_b)->next != *stack_b)
			ft_ps_rotate_b(stack_b, mvtbook);
	}
} //(b = destination)



void	ft_ps_pushorganise_as(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	ft_ps_push_a(stack_a, stack_b, mvtbook);
	if ((*stack_a)->rank > pivot)
		(*stack_a)->index = pivot + 1;
	else
	{
		(*stack_a)->index = pivot - 1;
		if ((*stack_a)->next != *stack_a)
			ft_ps_rotate_a(stack_a, mvtbook);
	}
} //(a = destination)
*/


/*************************************************
 * this function push_b and organise tack b according to the pivot.
 * and is also changing the inde1x to either pivot + 1 or pivot -1 so I can differentiate the groups
 */
/*
void	ft_ps_pass_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int pivot;
	int	chunck;

	chunck = (*stack_a)->index;
	pivot = ft_ps_chunckpivot(*stack_a, chunck);
	while ((*stack_a) && (*stack_a)->index == chunck)
		ft_ps_pushorganise_b(stack_a, stack_b, mvtbook, pivot);
	while (*stack_a)
	{
		chunck = (*stack_a)->index;
		pivot = ft_ps_chunckpivot(*stack_a, chunck);
		while ((*stack_a) && (*stack_a)->index == chunck)
			ft_ps_pushorganise_bs(stack_a, stack_b, mvtbook, pivot);
//		while ((*stack_b)->previous->index == pivot + 1)
//			ft_ps_reverse_b(stack_b, mvtbook);
	}
}

void	ft_ps_pass_a(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook)
{
	int pivot;
	int	chunck;

	chunck = (*stack_b)->index;
	pivot = ft_ps_chunckpivot(*stack_b, chunck);
	while ((*stack_b) && (*stack_b)->index == chunck)
		ft_ps_pushorganise_a(stack_a, stack_b, mvtbook, pivot);
	while (*stack_b)
	{
		chunck = (*stack_b)->index;
		pivot = ft_ps_chunckpivot(*stack_b, chunck);
		while ((*stack_b) && (*stack_b)->index == chunck)
			ft_ps_pushorganise_as(stack_a, stack_b, mvtbook, pivot);
//		while ((*stack_a)->previous->index == pivot - 1)
//			ft_ps_reverse_a(stack_a, mvtbook);
	}
	//NEED TO ADD A FUNCTION THAT ROTATE TO FIRST SMALLEST CHUNCK.
}*/

void	ft_ps_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	ft_ps_push_b(stack_b, stack_a, mvtbook);
	if ((*stack_b)->rank <= pivot / 2)
	{
		(*stack_b)->index = pivot - 1;
		if ((*stack_b)->next != *stack_b)
			ft_ps_rotate_b(stack_b, mvtbook);
	}
	else
		(*stack_b)->index = pivot + 1;
} //(b = destination)

void	ft_ps_pushorganise_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	ft_ps_push_a(stack_a, stack_b, mvtbook);
	if ((*stack_a)->rank > pivot / 2)
	{
		(*stack_a)->index = pivot + 1;
		if ((*stack_a)->next != *stack_a)
			ft_ps_rotate_a(stack_a, mvtbook);
	}
	else
		(*stack_a)->index = pivot - 1;
} //(a = destination)

int	ft_ps_is_even_nbr(int n)
{
	if (n == 0 || n == -1 || n == 1 )
		return (0);
	if (n % 2 == 0 || n == 2)
		return (1);
	return (0);
}

void	ft_ps_pass_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int		len;
	int		pivot;
	int		count;

	len = ft_ps_chunck_len(*stack_a);
	pivot = ft_ps_chunckpivot(*stack_a, (*stack_a)->index);
	count = len / 2;
	if (!ft_ps_is_even_nbr(len))
		count++;
	while (count)
	{
		if ((*stack_a)->rank <= pivot && count--)
			ft_ps_pushorganise_b(stack_a, stack_b, mvtbook, pivot);
		else
			ft_ps_rotate_a(stack_a, mvtbook);
	}
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
	printf("\n\n\n");
}

void	ft_ps_pass_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int		len;
	int		pivot;
	int		count;

	len = ft_ps_chunck_len(*stack_b);
	pivot = ft_ps_chunckpivot(*stack_b, (*stack_b)->index);
	count = len / 2;
	if (!ft_ps_is_even_nbr(len))
		count++;
	while (count)
	{
		if ((*stack_b)->rank >= pivot && count--)
			ft_ps_pushorganise_a(stack_a, stack_b, mvtbook, pivot);
		else
			ft_ps_rotate_b(stack_b, mvtbook);
	}
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
	printf("\n\n\n");
}

void	ft_ps_sort(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook)
{
	int	pivot;

	if (ft_ps_chunck_len(*stack_a) > 5)
	{
		ft_ps_pass_b(stack_a, stack_b, mvtbook);
		ft_ps_sort(stack_a, stack_b, mvtbook);
	}

//	ft_ps_pass_a(stack_a, stack_b, mvtbook); 

	/*
	if (ft_ps_stacklen(*stack_b) > 3)
	{
		pivot = ft_ps_findpivot(*stack_a);
		ft_ps_pass_b(stack_a, stack_b, mvtbook, pivot);
		ft_ps_sort(stack_a, stack_b, mvtbook);
	}*/
}

/******************to do list******************
 * need to finish the recursive. now stuf has to go back on stack a according to the pivot.
 */
