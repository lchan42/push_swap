/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/23 18:24:09 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_targetedrot(t_stack **stack, t_list **mvtbook, t_stack *target, char *mvt)
{
	if (ft_strncmp("ra", mvt, 2) == 0)
		while (*stack != target)
			ft_ps_rotate_a(stack, mvtbook);
	else if (ft_strncmp("rra", mvt, 3) == 0)
		while (*stack != target)
			ft_ps_reverse_a(stack, mvtbook);
	else if (ft_strncmp("rb", mvt, 2))
		while (*stack != target)
			ft_ps_rotate_b(stack, mvtbook);
	else if (ft_strncmp("rrb", mvt, 3))
		while (*stack != target)
			ft_ps_reverse_b(stack, mvtbook);
}
/***************************************************
 * rotate or reverse towards target.
*/

/*********************************************sorting < 5**************************************************/
int	ft_ps_smartrotation_a_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len)
{
	int	indice;

	indice = 0;
	while (len-- && indice == 0)
	{
		*tmp = (*tmp)->next;
		*r_tmp = (*r_tmp)->previous;
		if ((*tmp)->rank < pivot)
			indice = 1;
		else if ((*r_tmp)->rank < pivot)
			indice = -1;
	}
	return (indice);
}
int	ft_ps_smartrotation_a(t_stack **stack, t_list **mvtbook, int pivot)
{
	t_stack	*tmp;
	t_stack *r_tmp;
	int		indice;
	int 	len;

	if ((*stack)->rank < pivot)
		return (1);
	tmp = *stack;
	r_tmp = *stack;
	indice = ft_ps_smartrotation_a_bis(&tmp, &r_tmp, pivot, ft_ps_stacklen(*stack));
	if (indice == 0)
		return 0;
	else if (indice == 1)
		ft_ps_targetedrot(stack, mvtbook, tmp, "ra");
	else if (indice == -1)
		ft_ps_targetedrot(stack, mvtbook, r_tmp, "rra");
	return (1);
}
/**************************************************************
 * find the shortest way towards element that have to be pushed;
 */










/*******************************************************
 * if there is more than 2 element, use b3 else use b2;
 */

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
		ft_ps_rotate_a(stack_b, mvtbook);
	else if (current < next && current > bignext) //2 3 1
		ft_ps_swap_b(stack_b, mvtbook);
	else if (current < next && next < bignext) //1 2 3
	{
		ft_ps_rotate_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
	}
	else if (current > bignext && next < bignext) //3 1 2 
	{	
		ft_ps_reverse_b(stack_b, mvtbook);
		ft_ps_swap_b(stack_b, mvtbook);
	}
}
void	ft_ps_sort_back_b_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int count)
{
	int stack_len;
	int	chunck_len;

	stack_len = ft_ps_stacklen(*stack_b);
	if (stack_len <= 5)
	{
		if (count == 2)
			ft_ps_sort_b2(stack_b, mvtbook);
		else if (count == 3)
			ft_ps_sort_b3_cir(stack_b, mvtbook);
//		else if (count > 3)
//			ft_ps_sort_b5_cir(stack_a, stack_b, mvtbook);
	}
}

void	ft_ps_sort_a2(t_stack **stack_a, t_list **mvtbook)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_ps_swap_a(stack_a, mvtbook);
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

void	ft_ps_sort_a5_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int	stack_len;
	int pivot;
	int	len;
	int count;

	stack_len = ft_ps_stacklen(*stack_a);
	count = 0;
	if (ft_ps_sorted_checker_a_n(*stack_a, stack_len))
		return ;
	if (stack_len > 3)
	{	
		pivot = ft_ps_findpivot(*stack_a);
		while (ft_ps_smartrotation_a(stack_a, mvtbook, pivot))
			if ((*stack_a)->rank < pivot && ++count)
				ft_ps_push_b(stack_b, stack_a, mvtbook);
	}
	ft_ps_sort_a3_cir(stack_a, mvtbook);
	printf("count = %d\n", pivot);
	ft_ps_sort_back_b_cir(stack_a, stack_b, mvtbook, count);
	while (count--)
		ft_ps_push_a(stack_a, stack_b, mvtbook);
}

/*
void	ft_ps_sort_a10_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int	stack_len;
	int pivot;
	int count;

	stack_len = ft_ps_stacklen(*stack_a);
	count = 0;
	if (ft_ps_sorted_checker_a_n(*stack_a, stack_len))
		return ;
	if (stack_len > 5)
	{	
		pivot = ft_ps_findpivot(*stack_a);
			while (ft_ps_smartrotation_a(stack_a, mvtbook, pivot))
				if ((*stack_a)->rank < pivot && ++count)
					ft_ps_push_b(stack_b, stack_a, mvtbook); //or pushorganise ? 
	}
	ft_ps_sort_a5_cir(stack_a, mvtbook);
	ft_ps_sort_back_b_cir(stac_a, stack_b, mvtbook, count);
	while (count--)
		ft_ps_push_a(stack_a, stack_b, mvtbook);
}
*/


/*
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
*/


/************************************************************
 *this function only works if entry is <= 5/
 */
/*************************************************************************************************************/






/**************************the goal here is to do an algorythm that sort_5 with no rotation***********************/
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
	else if (current < bignext && bignext < next) //1 3 2 ++
	{ 
		ft_ps_rotate_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook); //we end up with 1 2 3, head on 2; 
	}
	else if (current > next && current < bignext) //2 1 3
		ft_ps_swap_a(stack_a, mvtbook);
	else if (current < next && current > bignext) //2 3 1 ++
		ft_ps_reverse_a(stack_a, mvtbook);
	else if (current > next && next > bignext) //3 2 1++
	{
		ft_ps_rotate_a(stack_a, mvtbook);
		ft_ps_swap_a(stack_a, mvtbook);
	}
	else if (current > bignext && next < bignext) //3 1 2 ++
		ft_ps_rotate_a(stack_a, mvtbook);
}

int	ft_ps_push_b_count(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	if (!*stack_a)
		return (0);
	ft_ps_push_b(stack_b, stack_a, mvtbook);
	return (1);
}

int	ft_ps_push_a_count(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	if (!*stack_b)
		return (0);
	ft_ps_push_a(stack_a, stack_b, mvtbook);
	return (1);
}

void	ft_ps_push_back_a_n(t_stack **dst, t_stack **src, t_list **mvtbook, int n)
{
	while (n--)
		ft_ps_push_a(dst, src, mvtbook);
}

void	ft_ps_push_back_b_n(t_stack **dst, t_stack **src, t_list **mvtbook, int n)
{
	while (n--)
		ft_ps_push_b(dst, src, mvtbook);
}
	
/****************************************************************
 * this function has to be used during the last sorting, when all chunch are less than 10;
 * sort 3 first didgit
 * go to next chunck
 * push back element from stack b
 */


void	ft_ps_sort_a5(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int	chunck_len;
	int count;
	int tmp;
	int	pivot;
	
	chunck_len = ft_ps_chunck_len(*stack_a);
	if (ft_ps_sorted_checker_a_n(*stack_a, chunck_len))
		return ;
	pivot = ft_ps_chunckpivot(*stack_a, (*stack_a)->index);
	if (chunck_len > 3)
/*	while (1)
	{
		stack_a; 
	}*/
	ft_ps_sort_a3_cir(stack_a, mvtbook);
//	ft_ps_sort_b2(stack_b, mvtbook); deleted function
//	ft_ps_npush_a(stack_a, stack_b, mvtbook, count); deleted function
}
