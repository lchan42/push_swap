/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/26 17:37:15 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_sort_back_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count)
{
	if (count == 2)
		ft_ps_sort_b2(stack_b, mvtbook);
	else if (count == 3 && ft_ps_stacklen(*stack_b) == 3)
		ft_ps_sort_b3_cir(stack_b, mvtbook);
	else if (count == 3)
		ft_ps_sortcnt_b3(stack_a, stack_b, mvtbook, &count);
	while (count--)
	{
		printf("pushing %d, count = %d\n", (*stack_b)->rank, count);
		ft_ps_push_a(stack_a, stack_b, mvtbook);
	}
}
/********************************************************
 * in this case no push back from a. We are pushing sorted element from b.
 */

void	ft_ps_pushcnt_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *count)
{
	ft_ps_push_a(stack_a, stack_b, mvtbook);
	*count = *count - 1;
}

void	ft_ps_sortcnt_b3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int *count)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_b)->rank;
	next = (*stack_b)->next->rank;
	bignext = (*stack_b)->next->next->rank;
	printf("current = %d, next = %d, bignext = %d", current, next, bignext);
	if (current > next && next > bignext) //3 2 1
		return ;
	else if (current < bignext && bignext < next) //1 3 2
	{
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_pushcnt_a(stack_a, stack_b, mvtbook, count);
		del_print_circular_lst(*stack_a, 'a', 0);
		ft_ps_swap_b(stack_b, mvtbook);
	}
	else if (current > next && current < bignext) //2 1 3
	{
		ft_ps_rotate_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_pushcnt_a(stack_a, stack_b, mvtbook, count);	
		ft_ps_reverse_b(stack_b, mvtbook);
	}
	 if (current < next && current > bignext) //2 3 1	
		ft_ps_swap_b(stack_b, mvtbook);
	else if (current < next && next < bignext) //1 2 3
	{	
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_rotate_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
		ft_ps_pushcnt_a(stack_a, stack_b, mvtbook, count);	
		ft_ps_reverse_b(stack_b, mvtbook);
	}
	else if (current > bignext && next < bignext) //3 1 2
	{	
		ft_ps_pushcnt_a(stack_a, stack_b, mvtbook, count);	
		ft_ps_swap_b(stack_b, mvtbook);
	}
}

void	ft_ps_sort_b3(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
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
		ft_ps_sort_b3_bis(stack_a, stack_b, mvtbook);
}

void	ft_ps_sort_b3_bis(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_b)->rank;
	next = (*stack_b)->next->rank;
	bignext = (*stack_b)->next->next->rank;
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
		ft_ps_sort_b3(stack_a, stack_b, mvtbook);
	while (count--)
		ft_ps_push_b(stack_a, stack_b, mvtbook);
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
//--> have to check if it works
void	ft_ps_sort_a6(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int	chunck_len;
	int pivot;
	int count;

	chunck_len = ft_ps_chunck_len(*stack_a);
	count = 0;
	if (ft_ps_sorted_checker_a_n(*stack_a, chunck_len))
		return ;
	if (chunck_len > 3)
	{	
		pivot = ft_ps_chunckpivot(*stack_a);
		while (chunck_len > 3)
			if ((*stack_a)->rank <= pivot && ++count)
				ft_ps_push_b(stack_b, stack_a, mvtbook);
	}
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
	ft_ps_sort_a3(stack_a, stack_b,  mvtbook);
	ft_ps_sort_back_a(stack_a, stack_b, mvtbook, count);
}

