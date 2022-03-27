/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:16:22 by lchan             #+#    #+#             */
/*   Updated: 2022/03/27 21:20:19 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverseback_a(t_stack **stack_a, t_list **mvtbook, int index)
{
	while ((*stack_a)->previous->index == index)
		ft_ps_reverse_a(stack_a, mvtbook);
}

void	ps_reverseback_b(t_stack **stack_b, t_list **mvtbook, int index)
{
	while ((*stack_b)->previous->index == index)
		ft_ps_reverse_b(stack_b, mvtbook);
}

void	ps_rotscanb_push_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *len)
{
	int	pivot;
	int	pushable;
	int	index;
	int	intern_pivot;

	pivot = ft_ps_chunckpivot(*stack_b);
	pushable = (*len) / 2;
	intern_pivot = pivot + (pushable / 2);
	index = (*stack_b)->index;
	while (pushable)
	{
		if ((*stack_b)->rank > pivot && pushable--)
		{
			ft_ps_pushcnt_a(stack_a, stack_b, mvtbook, len);
			if ((*stack_a)->rank <= intern_pivot)
				ft_ps_rotate_a(stack_a, mvtbook);
		}
		if (pushable)
			ft_ps_rotate_b(stack_b, mvtbook);
	}
	ft_ps_sortsmall_a(stack_a, stack_b, mvtbook, ft_ps_chunck_len(*stack_a));
	printf("chunck_len = %d\n\n", ft_ps_chunck_len(*stack_a));
	ps_reverseback_a(stack_a, mvtbook, index);
	ft_ps_sort_a2(stack_a, mvtbook);
}
/*****************************************************
 * rotate and push_a organise with out changing index;
 * sort small_a, reverse back and sort 2;
 */

void	ps_revscanb_push_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *len)
{	
	int	pivot;
	int	pushable;
	int index;

	pivot = ft_ps_targeted_chunckpivot(*stack_b, (*stack_b)->index);
	pushable = (*len) / 2;
	index = (*stack_b)->index;
	while (*len > 3)
	{
		if ((*stack_b)->rank > pivot)
			ft_ps_pushcnt_a(stack_a, stack_b, mvtbook, len);
		if ((*stack_b)->previous->index == index)
			ft_ps_reverse_b(stack_b, mvtbook);
	}
	ft_ps_sortsmall_a(stack_a, stack_b, mvtbook, pushable);
	ps_reverseback_b(stack_b, mvtbook, index);
	ft_ps_sort_back_b(stack_a, stack_b, mvtbook, *len);
}

void	ps_chunck_scanpush_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	len;
	int	index;

	len = ft_ps_chunck_len(*stack_b);
	index = (*stack_b)->index;
//	while (len)
//	{
		if (len <= 3)
		{
			ft_ps_sort_back_b(stack_a, stack_b, mvtbook, len);
		}
		else if (len <= 10)
		{
			ps_rotscanb_push_a(stack_a, stack_b, mvtbook, &len);//divide chunck by 2
			if ((*stack_b)->index != index)
				ft_ps_reverse_b(stack_b, mvtbook);
			ps_revscanb_push_a(stack_a, stack_b, mvtbook, &len);
//			printf("len in chunck_scan = %d\n", len);
		}
//	}
}
