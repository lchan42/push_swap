/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/20 20:20:11 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
		ft_ps_push_b(stack_b, stack_a, mvtbook);
		if ((*stack_b)->rank <= pivot)
		{
			(*stack_b)->index = pivot - 1;
			if ((*stack_b)->next->rank > pivot)
				ft_ps_rotate_b(stack_b, mvtbook);
		}
		else
			(*stack_b)->index = pivot + 1;
} //(b = destination)

void	ft_ps_pass_b(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook)
{
	int pivot;
	int	chunck;

	while (*stack_b)
	{
		chunck = (*stack_b)->index;
		pivot = ft_ps_chunckpivot(*stack_b, chunck);
		printf("chunck pivot = %d\n", pivot);
		while ((*stack_b) && (*stack_b)->index == chunck)
			ft_ps_pushorganise_a(stack_a, stack_b, mvtbook, pivot);
	}
}

/*************************************************
 * this function push_b and organise tack b according to the pivot.
 * and is also changing the inde1x to either pivot + 1 or pivot -1 so I can differentiate the groups
 */

void	ft_ps_pushorganise_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
		ft_ps_push_a(stack_a, stack_b, mvtbook);
		if ((*stack_a)->rank > pivot)
		{
			(*stack_a)->index = pivot + 1;
			if ((*stack_a)->next->rank <= pivot)
				ft_ps_rotate_a(stack_a, mvtbook);
		}
		else
			(*stack_a)->index = pivot - 1;
} //(a = destination) 

void	ft_ps_pass_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int pivot;
	int	chunck;

	while (*stack_a)
	{
		chunck = (*stack_a)->index;
		pivot = ft_ps_chunckpivot(*stack_a, chunck);
		printf("chunck pivot = %d\n", pivot);
		while ((*stack_a) && (*stack_a)->index == chunck)
			ft_ps_pushorganise_b(stack_a, stack_b, mvtbook, pivot);
	}
}
/*
void	ft_ps_juggle(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook)
{
	ft_ps_pass_a(stack_a, stack_b, mvtbook);
	printf("max_chunck_b  = %d\n", ft_ps_chunckmax_len(*stack_b));
}
*/
void	ft_ps_juggle(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook)
{
	while (ft_ps_chunckmax_len(*stack_a) > 10)
	{
		ft_ps_pass_a(stack_a, stack_b, mvtbook);
		if ((ft_ps_chunckmax_len(*stack_b) <= 10))
			break ;
		ft_ps_pass_b(stack_a, stack_b, mvtbook);
	}
	printf("max_chunck_b  = %d\n", ft_ps_chunckmax_len(*stack_b));
}

/******************to do list******************
 * stop the sorting at 10 or less on either stack.
 * find a way to juggle with chunck in order.
 */
