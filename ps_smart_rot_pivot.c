/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 21:07:05 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_smart_a_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len)
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

int	ft_ps_smartrotation_a(t_stack **stack, t_list **m, int pivot)
{
	t_stack	*tmp;
	t_stack *r_tmp;
	int		indice;
	int 	len;

	if ((*stack)->rank < pivot)
		return (1);
	tmp = *stack;
	r_tmp = *stack;
	len = ft_ps_stacklen(*stack);
	indice = ft_ps_smart_a_bis(&tmp, &r_tmp, pivot, len);
	if (indice == 0)
		return 0;
	else if (indice == 1)
		ft_ps_targetedrot(stack, m, tmp, "ra");
	else if (indice == -1)
		ft_ps_targetedrot(stack, m, r_tmp, "rra");
	return (1);
}
/**************************************************************
 * find the shortest way towards element that have to be pushed;
 * if the len is even, pivot is incremented order to push half
 * 		(as smart_a_bis returns -1 or 1 if (*tmp)->rank < pivot)
 */


int	ft_ps_smart_b_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len)
{
	int	indice;

	indice = 0;
	while (len-- && indice == 0)
	{
		*tmp = (*tmp)->next;
		*r_tmp = (*r_tmp)->previous;
		if ((*tmp)->rank > pivot)
			indice = 1;
		else if ((*r_tmp)->rank > pivot)
			indice = -1;
	}
	return (indice);
}

int	ft_ps_smartrotation_b(t_stack **stack, t_list **m, int pivot)
{
	t_stack	*tmp;
	t_stack *r_tmp;
	int		indice;
	int 	len;

	if ((*stack)->rank > pivot)
		return (1);
	tmp = *stack;
	r_tmp = *stack;
	len = ft_ps_stacklen(*stack);
	indice = ft_ps_smart_b_bis(&tmp, &r_tmp, pivot, len);
	if (indice == 0)
		return 0;
	else if (indice == 1)
		ft_ps_targetedrot(stack, m, tmp, "rb");
	else if (indice == -1)
		ft_ps_targetedrot(stack, m, r_tmp, "rrb");
	return (1);
}
