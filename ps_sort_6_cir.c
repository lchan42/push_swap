/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_6_cir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 21:15:17 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_sort_b3_cir(t_stack **b, t_list **m)
{
	int	current;
	int	next;
	int	bignext;

	current = (*b)->rank;
	next = (*b)->next->rank;
	bignext = (*b)->next->next->rank;
	if (current > next && next > bignext)
		return ;
	else if (current < bignext && bignext < next)
		ft_ps_rotate_b(b, m);
	else if (current > next && current < bignext)
		ft_ps_reverse_b(b, m);
	else if (current < next && current > bignext)
		ft_ps_swap_b(b, m);
	else if (current < next && next < bignext)
	{
		ft_ps_swap_b(b, m);
		ft_ps_reverse_b(b, m);
	}
	else if (current > bignext && next < bignext) 
	{	
		ft_ps_swap_b(b, m);
		ft_ps_rotate_b(b, m);
	}
}
/*******************************************************
 * in order : 
 *  3 2 1
 *  1 3 2
 *  2 1 3
 *  2 3 1
 *  1 2 3
 *  3 1 2
 *  ****************************************************/

void	ft_ps_sort_a2(t_stack **a, t_list **m)
{
	if ((*a)->value > (*a)->next->value)
		ft_ps_swap_a(a, m);
}

void	ft_ps_sort_a3_cir(t_stack **a, t_list **m)
{
	int	current;
	int	next;
	int	bignext;

	current = (*a)->rank;
	next = (*a)->next->rank;
	bignext = (*a)->next->next->rank;
	if (ft_ps_sorted_checker(*a))
		return ;
	else if (current < bignext && bignext < next)
	{
		ft_ps_swap_a(a, m);
		ft_ps_rotate_a(a, m);
	}
	else if (current > next && current < bignext)
		ft_ps_swap_a(a, m);
	else if (current < next && current > bignext)
		ft_ps_reverse_a(a, m);
	else if (current > next && next > bignext)
	{
		ft_ps_rotate_a(a, m);
		ft_ps_swap_a(a, m);
	}
	else if (current > bignext && next < bignext)
		ft_ps_rotate_a(a, m);
}
/*******************************************************
 * in order : 
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 2 1
 * 3 1 2 
 * *****************************************************/

void	ft_ps_sort_back_a_cir(t_stack **a, t_stack **b, t_list **m, int count)
{
	if (count == 2 && (*b)->value < (*b)->next->value)
		ft_ps_swap_b(b, m);
	else if (count == 3)
		ft_ps_sort_b3_cir(b, m);
	while (count--)
		ft_ps_push_a(a, b, m);
}

void	ft_ps_sort_a6_cir(t_stack **a, t_stack **b, t_list **m)
{
	int	stack_len;
	int pivot;
	int count;

	stack_len = ft_ps_chunck_len(*a);
	count = 0;
	if (ft_ps_is_sorted(*a))
		ps_smrtrot_target_a(a, m, 1);
	else if (stack_len <= 2)
		ft_ps_sort_a2(a, m);
	else if (stack_len >= 3)
	{
		pivot = ft_ps_intern_pivot_a(stack_len, ft_ps_findpivot(*a));
		while (stack_len > 3)
			if (ft_ps_smartrotation_a(a, m, pivot) && --stack_len && ++count)
				ft_ps_push_b(b, a, m);
		ft_ps_sort_a3_cir(a, m);
		ft_ps_sort_back_a_cir(a, b, m, count);
	}
}
