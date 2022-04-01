/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:14:54 by lchan             #+#    #+#             */
/*   Updated: 2022/04/01 15:16:10 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_findchkminval(t_stack *stack, int index)
{
	int		len;
	int		tmp;
	t_stack	*min;

	len = ft_ps_stacklen(stack);
	tmp = len;
	while (stack->previous->index == index && tmp--)
		stack = stack->previous;
	min = stack;
	while (stack->index == index && len--)
	{
		if (min->rank > stack->rank)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*ps_findchkmaxval(t_stack *stack, int index)
{
	int		len;
	int		tmp;
	t_stack	*max;

	len = ft_ps_stacklen(stack);
	tmp = len;
	while (stack->previous->index == index && tmp--)
		stack = stack->previous;
	max = stack;
	while (stack->index == index && len--)
	{
		if (max->rank < stack->rank)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack *ps_findchkmidval(t_stack *dst, t_stack *src )
{
	int		len;
	int		index;
	int		tmp;
	t_stack	*target;

	len = ft_ps_stacklen(dst);
	index = src->index;
	while (dst->previous->index == index && tmp--)
		dst = dst->previous;
	target = ps_findchkmaxval(dst, src->index);
	while (dst->index == index && len--)
	{
		tmp = dst->rank - src->rank;
		if (tmp > 0 && tmp < target->rank - src->rank)
			target = dst;
		dst = dst->next;
	}
	return (target);
}

int ps_findtarget(t_stack *dst, t_stack *src)
{
	t_stack	*min;
	t_stack	*max;
	t_stack *mid;
	int		target;
	
	min = ps_findchkminval(dst, src->index);
	max = ps_findchkmaxval(dst, src->index);
	if (src->rank < min->rank)
		target = min->rank;
	else if (src->rank > max->rank)
		target = max->next->rank;
	else
	{
		mid = ps_findchkmidval(dst, src);
		target = mid->rank;
	}
	return (target);
}
