/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/14 19:55:09 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_stacklen(t_stack *head)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	if (head)
	{
		tmp = head->next;
		while (++len && tmp != head)
			tmp = tmp->next;
	}
	return (len);
}

int	ft_ps_findpivot(t_stack *head)
{
	t_stack	*tmp;
	int		pivot;

	tmp = head->next;
	pivot = head->rank;
	while (tmp != head)
	{
		pivot += tmp->rank;
		tmp = tmp->next;
	}
	return (pivot / ft_ps_stacklen(head));
}
/****************************************
 * returns the aritmetic average of a stack;
 */

int	ft_ps_chuckpivot (void)
{
	return (0);
}
	
int	ft_ps_sorted_checker(t_stack *head)
{
	int		len;
	t_stack	*tmp;

	len = ft_ps_stacklen(head);
	tmp = head;
	while (tmp->next != head)
	{
		if (tmp->rank != tmp->next->rank - 1)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->rank == len)
		return (1);
	return (0);
}
/*********************************************
 * this function is checking if the list is sorted or not
 */

/***************************************************AFTER SICKNESS*******************************************/

int	is_circle_sorted(t_stack *head)
{
	while (head->rank != 1)
		head = head->next;
	while (head->next->rank != 1)
	{
		if (head->next->rank != head->rank + 1)
			return (0);
		head = head->next;
	}
	return (1);
}
/**************************************************
 * not sure it will be usefull;
 * this function was meant to check if a stack only needs rotation to be sorted.
 * it could be use for optimisation
 */

void	ft_ps_goto_target_a(t_stack **head, int target, t_list **mvtbook)
{
	t_stack	*tmp;
	int		rota;
	int		rev_rota;

	rota = 0;
	rev_rota = 0;
	tmp = *head;
	while (tmp->rank != target && ++rota)
		tmp = tmp->next;
	tmp = *head;
	while (tmp->rank != target && ++rev_rota)
		tmp = tmp->previous;
	if (rota <= rev_rota)
		while ((*head)->rank != target)
			ft_ps_rotate_a (head, mvtbook);
	else if (rev_rota < rota)
		while ((*head)->rank != target)
			ft_ps_reverse_a (head, mvtbook);
}
/***************************************************
 * this function has to go in movement
*/

// void ft_ps_smart_rotation_a(t_stack **head, )
/***************************************************
 * this function returns a string that will tell us what rotation to use to reach the target.
 */

void	ft_ps_sort_a3(t_stack **stack_a, t_list **mvtbook)
{
	int	current;
	int	next;
	int	bignext;

	current = (*stack_a)->rank;
	next = (*stack_a)->next->rank;
	bignext = (*stack_a)->next->next->rank;
//	printf("current = %d, next = %d, bignext = %d\n", current, next, bignext);
	if (ft_ps_sorted_checker(*stack_a)) //1 2 3
	{
		printf("sorted\n\n\n");
		return ;
	}
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
/*
void	ft_ps_sort_small_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int		pivot;
	t_stack	tmp;
	if (ft_ps_sorted_checker(*stack_a))
	{
		printf("already sorted\n");
		return ;
	}
	else if (is_circle_sorted(*stack_a))
		ft_ps_goto_target_a(stack_a, 1, mvtbook);
	else
		ft_ps_quicksort_a(stack_a, stack_b, mvtbook);
}

void	ft_ps_quicksort_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{	
	int		pivot;
	int		len;
	
	pivot = ft_ps_findpivot(*stack_a);
	len = ft_ps_stacklen(*stack_a);

	printf("pivot = %d, \nlen = %d", pivot, len);
	while (len > 3)
	{
		if ((*stack_a)->rank < pivot)
		{
			push(stack_b, stack_a, mvtbook, "pa");
			len--;
		}
		else
			rotate(stack_a, NULL, mvtbook, "ra");
	}

}
*/
// might have to do a function that sort stack that are smaller than 5
//
/*********************************************
 * condition de backtracking
 * 		stack b empty, stack a has all the different digit
 *		rank of stack a are following each other
 *
 *
 *	other
 *	 
 *		cost compilator and cost comparator;
 *		*/
