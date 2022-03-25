/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/25 21:30:41 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_pivot_mark(t_stack *head, int pivot) //might not be usefull ?? 
{
	int	intern_pivot;
	int	chunck_len;
	int	sub_pivot;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_len = ft_ps_chunck_len(head);
	sub_pivot = ft_ps_subpivot(head, pivot);
	while (chunck_len--)
	{
		if (head->rank < intern_pivot)
			head->index = sub_pivot;
//		else
//			head->index = pivot + 1;
		head = head->next;
	}
}

int		ft_ps_intern_pivot(int chunck_len, int pivot)
{
	if (ft_ps_is_even_nbr(chunck_len))
		return (pivot + 1);
	return (pivot);
}

int	ft_ps_subpivot(t_stack *head, int pivot) //calculate in advance a pivot into a pivot group;
{
	int	intern_pivot;
	int	chunck_len;
	int	sub_len;
	int	sub_pivot;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_len = ft_ps_chunck_len(head);
	sub_len = 0;
	sub_pivot = 0;
	while (chunck_len--)
	{
		if (head->rank < intern_pivot && ++sub_len)
			sub_pivot += head->rank;
		head = head->next;
	}
	if (sub_pivot == 0 || sub_len == 0)
		return (0);
	return (sub_pivot/sub_len);
}

int	ft_ps_count_underpivot(t_stack *head, int pivot) //for stack_a
{
	int	intern_pivot;
	int	chunck_index;
	int	chunck_len;
	int	count;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_index = head->index;
	chunck_len = ft_ps_chunck_len(head);
	count = 0;
	while (head->index == chunck_index && chunck_len--)
	{
		if (head->rank < intern_pivot)
			count++;
		head = head->next;
	}
	return (count);
}

int	ft_ps_count_overpivot(t_stack *head, int pivot) //for stack_b (count number of element over pivot)
{
	int	intern_pivot;
	int	chunck_index;
	int	chunck_len;
	int	count;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_index = head->index;
	chunck_len = ft_ps_chunck_len(head);
	count = 0;
	while (head->index == chunck_index && chunck_len--)
	{
		if (head->rank >= intern_pivot)
			count++;
		head = head->next;
	}
	return (count);
}

/**********************************************************************************************
 * 123 mvt for list 
 * 464 333 93 407 266 150 315 439 7 297 423 279 303 388 233 18 200 368 163 288 336 459 461 218 25 33 341 131 493 365 71 63 135 481 202 139 346 457 462 165 166 446 235 236 311 304 255 246 357 472 325 141 226 376 495 156 19 498 73 451 30 112 149 68 137 321 222 372 354 482 364 466 257 427 167 126 306 467 454 65 196 400 186 480 58 146 2 229 332 442 253 260 108 210 128 1 296 463 129 361
 */

void	ft_ps_orgapush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int subpivot)
{
	ft_ps_push_b(stack_b, stack_a, mvtbook);
	if ((*stack_b)->rank > subpivot)
		(*stack_b)->index = subpivot + 1;
	else
	{
		(*stack_b)->index = subpivot;
		if ((*stack_b)->next != *stack_b)
			ft_ps_rotate_b(stack_b, mvtbook);
	}
//	if ((*stack_b)->rank < (*stack_b)->next->rank) //need more testing to see if it's usefull or not;
//		ft_ps_swap_b(stack_b, mvtbook);
}

void	ft_ps_underpivotpush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	pivot;
	int	intern_pivot;
	int	subpivot;
	int	count;
	
	pivot = ft_ps_chunckpivot(*stack_a);
	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(*stack_a), pivot);
	subpivot = ft_ps_subpivot(*stack_a, pivot);
	count = ft_ps_count_underpivot(*stack_a, pivot);
	while (count)
	{
		if ((*stack_a)->rank < intern_pivot && count--)
			ft_ps_orgapush_b(stack_a, stack_b, mvtbook, subpivot);
		else
			ft_ps_rotate_a(stack_a, mvtbook);
	}
}

void	ft_ps_recursivepush(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	ft_ps_underpivotpush_b(stack_a, stack_b, mvtbook);
	if (ft_ps_stacklen(*stack_a) > 3)
		ft_ps_recursivepush(stack_a, stack_b, mvtbook);
}
