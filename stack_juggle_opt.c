/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/25 23:44:34 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ps_min_index(t_stack *head)
{
	t_stack	*tmp;
	int		min;

	tmp = head;
	min = head->index;
	while (tmp->next != head)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp ->next;
	}
	return (min);
}

int		ft_ps_max_index(t_stack *head)
{
	t_stack	*tmp;
	int		max;

	tmp = head;
	max = head->index;
	while (tmp->next != head)
	{
		if (tmp->index < max)
			max = tmp->index;
		tmp = tmp ->next;
	}
	return (max);
}

void	ft_ps_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	ft_ps_push_b(stack_b, stack_a, mvtbook);
	if ((*stack_b)->rank <= pivot / 2)
	{
		(*stack_b)->index = pivot - 1;
		if ((*stack_b)->next != *stack_b)
			ft_ps_rotate_b(stack_b, mvtbook);
	}
	else
		(*stack_b)->index = pivot + 1;
} //(b = destination)

void	ft_ps_pushorganise_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot)
{
	ft_ps_push_a(stack_a, stack_b, mvtbook);
	if ((*stack_a)->rank > pivot / 2)//not sure this is correct
	{
		(*stack_a)->index = pivot + 1;
//		if ((*stack_a)->next != *stack_a)
//			ft_ps_rotate_a(stack_a, mvtbook);
	}
	else
		(*stack_a)->index = pivot - 1;
} //(a = destination)

int	ft_ps_is_even_nbr(int n)
{
	if (n == 0 || n == -1 || n == 1 )
		return (0);
	if (n % 2 == 0 || n == 2)
		return (1);
	return (0);
}

void	ft_ps_pass_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int		len;
	int		pivot;
	int		count;

	len = ft_ps_chunck_len(*stack_a);
	pivot = ft_ps_chunckpivot(*stack_a);
	count = len / 2;
	if (!ft_ps_is_even_nbr(len))
		count++;
	while (count)
	{
		if ((*stack_a)->rank <= pivot && count--)
			ft_ps_pushorganise_b(stack_a, stack_b, mvtbook, pivot);
		else
			ft_ps_rotate_a(stack_a, mvtbook);
	}
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
	printf("\n\n\n");
}

void	ft_ps_pass_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int		len;
	int		pivot;
	int		count;

	len = ft_ps_chunck_len(*stack_b);
	pivot = ft_ps_chunckpivot(*stack_b);
	count = len / 2;
	if (!ft_ps_is_even_nbr(len))
		count++;
	while (count)
	{
		if ((*stack_b)->rank >= pivot && count--)
			ft_ps_pushorganise_a(stack_a, stack_b, mvtbook, pivot);
		else
			ft_ps_rotate_b(stack_b, mvtbook);
	}
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
	printf("\n\n\n");
}

/*objectif see if using smart rotation for the first cut is usefull or not */
/*see if using 2 pivot is usefull or not*/
void	ft_first_cut(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int len;
	int	pivot;

	len = ft_ps_chunck_len(*stack_a);

}


void	ft_ps_marksorted_a_b(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_ps_stacklen(stack_a);
	len_b = ft_ps_stacklen(stack_b);
	stack_a = stack_a->previous;
	while (len_a--)
	{
		if (stack_a->rank == stack_a->previous->rank + 1)
			stack_a->index = -1;
		else
			break ;
		stack_a = stack_a->previous;
	}
	while (len_b--)
	{
		if (stack_b->rank == stack_b->next->rank + 1)
			stack_a->index = -1;
		stack_b = stack_b->next;
	}
}

void	ft_ps_resetchunck_a_b(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_ps_stacklen(stack_a);
	len_b = ft_ps_stacklen(stack_b);
	ft_ps_marksorted_a_b(stack_a, stack_b);
	while (len_a-- && stack_a->index != -1)
	{
		stack_a->index = 0;
		stack_a = stack_a->next;
	}
	while (len_b-- && stack_b->index != -1)
	{
		stack_b->index = 0;
		stack_b = stack_b->next;
	}
}

void	ft_ps_recsort_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	chunck_len;

	if ((*stack_b)->index >= 0 && ft_ps_chunck_len(*stack_b) > 5)
	{
		ft_ps_pass_a(stack_a, stack_b, mvtbook);
		ft_ps_recsort_b(stack_a, stack_b, mvtbook);
	}
	chunck_len = ft_ps_chunck_len(*stack_a);
//	if (chunck_len <= 3)
//		ft_ps_sort_back_a(stack_a, stack_b, mvtbook, chunck_len);		
}

void	ft_ps_recsort_a(t_stack **stack_a, t_stack **stack_b, t_list**mvtbook)
{
	int	chunck_len;

	if (/*(*stack_a)->index >= 0 &&*/ ft_ps_chunck_len(*stack_a) > 5)
	{
		ft_ps_pass_b(stack_a, stack_b, mvtbook);
		ft_ps_recsort_a(stack_a, stack_b, mvtbook);
	}
	chunck_len = ft_ps_chunck_len(*stack_b);
	if (chunck_len <= 3)
		ft_ps_sort_back_b(stack_a, stack_b, mvtbook, chunck_len);
}

void	ft_ps_sort(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	//a
	ft_ps_recsort_a(stack_a, stack_b, mvtbook);
	if (ft_ps_stacklen(*stack_a) <= 5)
		ft_ps_sort_a6_cir(stack_a, stack_b, mvtbook);
	while ((*stack_a)->rank == (*stack_b)->rank + 1)
		ft_ps_push_a(stack_a, stack_b, mvtbook);


	ft_ps_resetchunck_a_b(*stack_a, *stack_b);
	
	//b
	ft_ps_recsort_b(stack_a, stack_b, mvtbook);
	if (ft_ps_stacklen(*stack_a) <= 5)
		ft_ps_sort_b6_cir(stack_a, stack_b, mvtbook);
}


/******************to do list******************
 * need to finish the recursive. now stuf has to go back on stack a according to the pivot.
 */
