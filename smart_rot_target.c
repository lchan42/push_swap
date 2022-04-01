/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/04/01 15:23:30 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	ft_ps_targetedrot(t_stack **stack, t_list **mvtbook, t_stack *target, char *mvt)
{
	if (ft_strncmp("ra", mvt, 2) == 0)
		while (*stack != target)
			ft_ps_rotate_a(stack, mvtbook);
	else if (ft_strncmp("rra", mvt, 3) == 0)
		while (*stack != target)
			ft_ps_reverse_a(stack, mvtbook);
	else if (ft_strncmp("rb", mvt, 2) == 0)
		while (*stack != target)
			ft_ps_rotate_b(stack, mvtbook);
	else if (ft_strncmp("rrb", mvt, 3) == 0)
		while (*stack != target)
			ft_ps_reverse_b(stack, mvtbook);
}*/
/***************************************************
 * rotate or reverse towards target.
*/

int	ps_smrtrot_target_a_bis(t_stack **tmp, t_stack **r_tmp, int target, int len)
{
	int	indice;

	indice = 0;
	while (len-- && indice == 0)
	{
		*tmp = (*tmp)->next;
		*r_tmp = (*r_tmp)->previous;
		if ((*tmp)->rank == target)
			indice = 1;
		else if ((*r_tmp)->rank == target)
			indice = -1;
	}
	return (indice);
}

int	ps_smrtrot_target_a(t_stack **stack, t_list **mvtbook, int target)
{
	t_stack	*tmp;
	t_stack *r_tmp;
	int		indice;
	int 	len;

	if ((*stack)->rank == target)
		return (1);
	tmp = *stack;
	r_tmp = *stack;
	len = ft_ps_stacklen(*stack);
	indice = ps_smrtrot_target_a_bis(&tmp, &r_tmp, target, len);
	if (indice == 0)
		return 0;
	else if (indice == 1)
		ft_ps_targetedrot(stack, mvtbook, tmp, "ra");
	else if (indice == -1)
		ft_ps_targetedrot(stack, mvtbook, r_tmp, "rra");
	return (1);
}

int	ps_smrtrot_target_b_bis(t_stack **tmp, t_stack **r_tmp, int target, int len)
{
	int	indice;

	indice = 0;
	while (len-- && indice == 0)
	{
		*tmp = (*tmp)->next;
		*r_tmp = (*r_tmp)->previous;
		if ((*tmp)->rank == target)
			indice = 1;
		else if ((*r_tmp)->rank == target)
			indice = -1;
	}
	return (indice);
}

int	ps_smrtrot_target_b(t_stack **stack, t_list **mvtbook, int target)
{
	t_stack	*tmp;
	t_stack *r_tmp;
	int		indice;
	int 	len;

	if ((*stack)->rank == target)
		return (1);
	tmp = *stack;
	r_tmp = *stack;
	len = ft_ps_stacklen(*stack);
	indice = ps_smrtrot_target_b_bis(&tmp, &r_tmp, target, len);
	if (indice == 0)
		return 0;
	else if (indice == 1)
		ft_ps_targetedrot(stack, mvtbook, tmp, "rb");
	else if (indice == -1)
		ft_ps_targetedrot(stack, mvtbook, r_tmp, "rrb");
	return (1);
}
