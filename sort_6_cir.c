/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a6_cir.c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/24 17:49:49 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_sort_b2(t_stack **stack_b, t_list **mvtbook)
{
	if ((*stack_b)->value < (*stack_b)->next->value)
		ft_ps_swap_b(stack_b, mvtbook);
}

void	ft_ps_sort_b3_cir(t_stack **stack_b, t_list **mvtbook)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_b)->rank;
	next = (*stack_b)->next->rank;
	bignext = (*stack_b)->next->next->rank;
	if (current > next && next > bignext) //3 2 1
		return ;
	else if (current < bignext && bignext < next) //1 3 2
		ft_ps_rotate_b(stack_b, mvtbook);
	else if (current > next && current < bignext) //2 1 3
		ft_ps_reverse_b(stack_b, mvtbook);
	else if (current < next && current > bignext) //2 3 1
		ft_ps_swap_b(stack_b, mvtbook);
	else if (current < next && next < bignext) //1 2 3
	{
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_reverse_b(stack_b, mvtbook);
	}
	else if (current > bignext && next < bignext) //3 1 2 
	{	
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_rotate_b(stack_b, mvtbook);
	}
}

void	ft_ps_sort_back_a_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count)
{
	if (count == 2)
		ft_ps_sort_b2(stack_b, mvtbook);
	else if (count == 3)
		ft_ps_sort_b3_cir(stack_b, mvtbook);
	while (count--)
		ft_ps_push_a(stack_a, stack_b, mvtbook);
}

void	ft_ps_sort_a3_cir(t_stack **stack_a, t_list **mvtbook)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_a)->rank;
	next = (*stack_a)->next->rank;
	bignext = (*stack_a)->next->next->rank;
	if (ft_ps_sorted_checker(*stack_a)) //1 2 3
		return ;
	else if (current < bignext && bignext < next) //1 3 2
	{
		ft_ps_swap_a(stack_a, mvtbook);
		ft_ps_rotate_a(stack_a, mvtbook);
	}
	else if (current > next && current < bignext) //2 1 3
		ft_ps_swap_a(stack_a, mvtbook);
	else if (current < next && current > bignext) //2 3 1
		ft_ps_reverse_a(stack_a, mvtbook);
	else if (current > next && next > bignext) //3 2 1
	{
		ft_ps_rotate_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
	}
	else if (current > bignext && next < bignext) //3 1 2 
		ft_ps_rotate_a(stack_a, mvtbook);
}

void	ft_ps_sort_a6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int	stack_len;
	int pivot;
	int count;

	stack_len = ft_ps_stacklen(*stack_a);
	count = 0;
	if (ft_ps_sorted_checker_a_n(*stack_a, stack_len))
		return ;
	if (stack_len > 3)
	{	
		pivot = ft_ps_findpivot(*stack_a);
		while (stack_len > 3)
			if (ft_ps_smartrotation_a(stack_a, mvtbook, pivot) && --stack_len && ++count)
				ft_ps_push_b(stack_b, stack_a, mvtbook);
	}
	ft_ps_sort_a3_cir(stack_a, mvtbook);
	ft_ps_sort_back_a_cir(stack_a, stack_b, mvtbook, count);
}

void	ft_ps_sort_a10_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int	stack_len;
	int pivot;
	int count;

	stack_len = ft_ps_stacklen(*stack_a);
	count = 0;
	if (ft_ps_sorted_checker_a_n(*stack_a, stack_len))
		return ;
	if (stack_len > 3)
	{	
		pivot = ft_ps_findpivot(*stack_a);
		while (stack_len > 3)
			if (ft_ps_smartrotation_a(stack_a, mvtbook, pivot) && --stack_len && ++count)
				ft_ps_push_b(stack_b, stack_a, mvtbook);
	}
	ft_ps_sort_a3_cir(stack_a, mvtbook);
	ft_ps_sort_back_a_cir(stack_a, stack_b, mvtbook, count);
}
/************************************************************
 *this function only works if entry is <= 6/
 */
/*************************************************************************************************************/

