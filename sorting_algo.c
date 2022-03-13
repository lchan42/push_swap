/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/13 22:16:02 by lchan            ###   ########.fr       */
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
	printf("%d %d", rota, rev_rota);
	if (rota <= rev_rota)
		while ((*head)->rank != target)
			rotate (head, NULL, mvtbook, "ra");
	else if (rev_rota < rota)
		while ((*head)->rank != target)
			reverse_rotate (head, NULL, mvtbook, "rra");
}

// void ft_ps_smart_rotation_a(t_stack **head, )
/***************************************************
 * this function returns a string that will tell us what rotation to use to reach the target.
 */

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
	while (len > pivot)
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
