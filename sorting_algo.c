/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/19 13:52:59 by lchan            ###   ########.fr       */
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

int	ft_ps_chunckpivot(t_stack *head, int chunck)
{
	t_stack	*tmp;
	int	pivot;
	int len;

	tmp = head->next;
	pivot = head->rank;
	len = 1;
	while ((tmp != head && tmp->index == chunck))
	{
		pivot += tmp->rank;
//		printf("rank = %d pivot = %d\n", tmp->rank, pivot);
		tmp = tmp->next;
		len++;
//		printf("len = %d\n", len);
	}
	return (pivot/len);
}
/****************************************
 * returns the aritmetic average of a stack;
 * take into account the rank;
 */

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

int	ft_ps_sorted_checker_n(t_stack *head, int n)
{
	int		len;
	t_stack	*tmp;

	len = ft_ps_stacklen(head);
	tmp = head;
	while (tmp->next != head && n--)
	{
		if (tmp->rank != tmp->next->rank - 1)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->rank == len)
		return (1);
	return (0);
}
/******************************************************
 * check if n element are sorted
 * */

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
	indice = 0;
	len = ft_ps_stacklen(*stack);
	while (len-- && indice == 0)
	{
		tmp = tmp->next;
		r_tmp = r_tmp->previous;
		if (tmp->rank < pivot)
			indice = 1;
		else if (r_tmp->rank < pivot)
			indice = -1;
	}
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
/*********************************************sorting < 5**************************************************/

void	ft_ps_sort_a3(t_stack **stack_a, t_list **mvtbook)
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

void	ft_ps_sort_b2(t_stack **stack_b, t_list **mvtbook)
{
	if ((*stack_b)->value < (*stack_b)->next->value)
		ft_ps_swap_b(stack_b, mvtbook);
}
/*******************************************************
 * if there is more than 2 element, use b3 else use b2;
 */

void	ft_ps_npush_a(t_stack **stack_a, t_stack** stack_b, t_list **mvtbook, int n)
{
	while (n--)
		ft_ps_push_a(stack_a, stack_b, mvtbook);
}

void	ft_ps_sort_b3(t_stack **stack_b, t_list **mvtbook)
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
void	ft_ps_quicksort_a5(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{
	int pivot;
	int	len;

	if (ft_ps_sorted_checker_n(*stack_a, 5))
		return ;
	pivot = ft_ps_findpivot(*stack_a);
	len = ft_ps_stacklen(*stack_a);
	if (len > 3)
		while (ft_ps_smartrotation_a(stack_a, mvtbook, pivot))
			if ((*stack_a)->rank < pivot)
				ft_ps_push_b(stack_b, stack_a, mvtbook);
	ft_ps_sort_a3(stack_a, mvtbook);
	ft_ps_sort_b2(stack_b, mvtbook);
	ft_ps_npush_a(stack_a, stack_b, mvtbook, 2);
}

void	ft_ps_quicksort_b5(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook) //MY PLAN IS TO DO A SORTER OF A10. THUS I NEED A SORT OF A5 AND B5.
{ //NEED TO CHANGE STUFF HERE, IT S JUST A COPY AND PAST OF THE a5 VERSION.
	int pivot;
	int	len;

	if (ft_ps_sorted_checker_n(*stack_a, 5))
		return ;
	pivot = ft_ps_findpivot(*stack_a);
	len = ft_ps_stacklen(*stack_a);
	if (len > 3)
		while (ft_ps_smartrotation_a(stack_a, mvtbook, pivot))
			if ((*stack_a)->rank < pivot)
				ft_ps_push_b(stack_b, stack_a, mvtbook);
	ft_ps_sort_a3(stack_a, mvtbook);
	ft_ps_sort_b2(stack_b, mvtbook);
	ft_ps_npush_a(stack_a, stack_b, mvtbook, 2);
}
/* unusefull function ?
void	ft_ps_quicksort_small(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook)
{	
	int pivot;
	int	len;

	if (ft_ps_sorted_checker(*stack_a))
		return ;
	pivot = ft_ps_findpivot(*stack_a);
	len = ft_ps_stacklen(*stack_a);
	while (len > 5)
		while (ft_ps_smartrotation_a(stack_a, mvtbook, pivot))
			if ((*stack_a)->rank < pivot)
				ft_ps_push_b(stack_b, stack_a, mvtbook);

}*/

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

/*void	ft_ps_juggle_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int pivot;
	int	len;
	int	chunck;

	pivot = ft_ps_findpivot(*stack_a);
		printf("pivot = %d\n", pivot);
	len = ft_ps_stacklen(*stack_a);
	while (*stack_a)
	{
		ft_ps_pushorganise_b(stack_a, stack_b, mvtbook, pivot);
	}
	del_print_circular_lst(*stack_b, 'b', 0);
	while (*stack_b)
	{
		chunck = (*stack_b)->index;
		pivot = ft_ps_chunckpivot(*stack_b, chunck);
		printf("chunck pivot = %d\n", pivot);
		while ((*stack_b) && (*stack_b)->index == chunck)
		{
			ft_ps_pushorganise_a(stack_a, stack_b, mvtbook, pivot);
		}
	}
}*/

int	ft_ps_chunckmax_len(t_stack *head)
{
	t_stack	*tmp;
	int		chunck;
	int		len;
	int		max_len;

	tmp = head;
	max_len = 0;
	if (head)
	{
		while (tmp->next != head)
		{
			chunck = tmp->index;
			len = 1;
			while (tmp->next != head && tmp->index == chunck)
			{
				len++;
				tmp = tmp->next;
			}
			if (len > max_len)
				max_len = len;
		}
	}
	return (max_len);
}

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

void	ft_ps_juggle(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook)
{
//	printf("stack len = %d\n", ft_ps_stacklen(*stack_a));
	while (ft_ps_chunckmax_len(*stack_a) > 10)
	{
		ft_ps_pass_a(stack_a, stack_b, mvtbook);
		ft_ps_pass_b(stack_a, stack_b, mvtbook);
	}


//	printf("max chunck  = %d\n", ft_ps_chunckmax_len(*stack_b));
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
