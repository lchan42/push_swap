/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/24 17:02:52 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_sort_back_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count)
{
	if (count == 2)
		ft_ps_sort_a2(stack_b, mvtbook);
	else if (count == 3 && ft_ps_stacklen(*stack_b) == 3)
		ft_ps_sort_a3_cir(stack_b, mvtbook);
	else if (count == 3)
		ft_ps_sort_a3(stack_b, mvtbook);
	while (count--)
		ft_ps_push_a(stack_a, stack_b, mvtbook);
}
/********************************************************
 * in this case no push back from a. We are pushing sorted element from b.
 */

void	ft_ps_sort_b3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_a)->rank;
	next = (*stack_a)->next->rank;
	bignext = (*stack_a)->next->next->rank;
	if (current > next && next > bignext) //3 2 1
		return ;
	else if (current < bignext && bignext < next) //1 3 2
	{
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_rotate_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_reverse_b(stack_b, mvtbook);
	}
	else if (current > next && current < bignext) //2 1 3
	{	
		ft_ps_rotate_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_reverse_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
	}
	else
		ft_ps_sort_b3_bis(stack_a, stack_b, mvtbook)
}

void	ft_ps_sort_b3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_a)->rank;
	next = (*stack_a)->next->rank;
	bignext = (*stack_a)->next->next->rank;
	 if (current < next && current > bignext) //2 3 1	
		ft_ps_swap_b(stack_b, mvtbook);
	else if (current < next && next < bignext) //1 2 3
	{	
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_rotate_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_reverse_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
	}
	else if (current > bignext && next < bignext) //3 1 2
	{	
		ft_ps_rotate_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_reverse_b(stack_b, mvtbook);
	}
}




void	ft_ps_sort_back_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count)
{
	if (count == 2)
		ft_ps_sort_b2(stack_b, mvtbook);
	else if (count == 3 && ft_ps_stacklen(*stack_b) == 3)
		ft_ps_sort_b3_cir(stack_b, mvtbook);
	else if (count == 3)
		ft_ps_sort_b3(stack_b, mvtbook);
	while (count--)
		ft_ps_push_a(stack_a, stack_b, mvtbook);
}

void	ft_ps_sort_a3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
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
		ft_ps_rotate_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
		ft_ps_reverse_a(stack_a, mvtbook);
	}
	else if (current < next && current > bignext) //2 3 1
	{
		ft_ps_rotate_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
		ft_ps_reverse_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
	}
	else	
		ft_ps_sort_a3_bis(stack_a, stack_b, mvtbook);
}
/**********************************************************
 * 123 132 231
 */

void	ft_ps_sort_a3_bis(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_a)->rank;
	next = (*stack_a)->next->rank;
	bignext = (*stack_a)->next->next->rank;		
	if (current > next && current < bignext) //2 1 3
		ft_ps_swap_a(stack_a, mvtbook);
	else if (current > bignext && next < bignext) //3 1 2 ++
	{
		ft_ps_swap_a(stack_a, mvtbook);
		ft_ps_rotate_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
		ft_ps_reverse_a(stack_a, mvtbook);
	}
	else if (current > next && next > bignext) //3 2 1++
	{
		ft_ps_swap_a(stack_a, mvtbook);
		ft_ps_rotate_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
		ft_ps_reverse_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
	}
}
/**********************************************************
 * 213 312 321
 */

void	ft_ps_sort_a6(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int	stack_len;
	int pivot;
	int count;

	chunck_len = ft_ps_chunck_len(*stack_a);
	count = 0;
	if (ft_ps_sorted_checker_a_n(*stack_a, chunck_len))
		return ;
	if (chunck_len > 3)
	{	
		pivot = ft_ps_chunckpivot(*stack_a, (*stack_a)->index);
		while (chunck_len > 3)
			if ((*stack_a)->rank <= pivot && ++count)
				ft_ps_push_b(stack_b, stack_a, mvtbook);
	}
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
	ft_ps_sort_a3(stack_a, mvtbook);
	ft_ps_sort_back_a(stack_a, stack_b, mvtbook, count);
}


/********************************************not finished**************maybe not usefull******************************/
void	ft_ps_smartrot_pushswap_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	int		count;
	int		reajust;
	t_stack	*current;
	t_stack	*next;

	count = ft_ps_count_underpivot(stack_a, pivot);
	reajust = 0;
	while (count)
	{
		current = stack_a;
		next = stack_a->next;
		if ((*stack_a)->rank <= pivot && count--)
			ft_ps_push_b(stack_a, stack_b, mvtbook);
		else if ((*stack_a)->rank <   && ++reajust)
	}
}

int	ft_ps_count_underpivot(t_stack *stack, int pivot) //for stack_a
{
	int	chunck_index;
	int	chunck_len;
	int	count;

	chunck_index = stack->index;
	chunck_len = ft_ps_chunck_len(stack);
	count = 0;
//	if (!ft_ps_is_even_nbr(pivot))
//		pivot--;
	while (stack->index == chunck_index && len--)
	{
		if (stack->index <= pivot)
			count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_ps_count_overpivot(t_stack *stack, int pivot) //for stack_b (count number of element over pivot)
{
	int	chunck_index;
	int	chunck_len;
	int	count;

	chunck_index = stack->index;
	chunck_len = ft_ps_chunck_len(stack);
	count = 0;
//	if (!ft_ps_is_even_nbr(pivot))
//		pivot--;
	while (stack->index == chunck_index && len--)
	{
		if (stack->index >=  pivot)
			count++;
		stack = stack->next;
	}
	return (count);
}


/******************** objectif of the day 
 * might be interesting to do a smart rot swap push --> rotate towards the target value, put push according to pivot and swap element if needed.
 */
