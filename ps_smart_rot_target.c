/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_rot_target.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 21:13:41 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_targetedrot(t_stack **stack, t_list **m, t_stack *targ, char *mvt)
{
	if (ft_strncmp("ra", mvt, 2) == 0)
		while (*stack != targ)
			ft_ps_rotate_a(stack, m);
	else if (ft_strncmp("rra", mvt, 3) == 0)
		while (*stack != targ)
			ft_ps_reverse_a(stack, m);
	else if (ft_strncmp("rb", mvt, 2) == 0)
		while (*stack != targ)
			ft_ps_rotate_b(stack, m);
	else if (ft_strncmp("rrb", mvt, 3) == 0)
		while (*stack != targ)
			ft_ps_reverse_b(stack, m);
}
/***********************************
 * rotate or reverse towards target.
************************************/

int	ps_smrtrot_target_a_bis(t_stack **tmp, t_stack **r_tmp, int targ, int len)
{
	int	indice;

	indice = 0;
	while (len-- && indice == 0)
	{
		*tmp = (*tmp)->next;
		*r_tmp = (*r_tmp)->previous;
		if ((*tmp)->rank == targ)
			indice = 1;
		else if ((*r_tmp)->rank == targ)
			indice = -1;
	}
	return (indice);
}

int	ps_smrtrot_target_a(t_stack **stack, t_list **m, int targ)
{
	t_stack	*tmp;
	t_stack *r_tmp;
	int		indice;
	int 	len;

	if ((*stack)->rank == targ)
		return (1);
	tmp = *stack;
	r_tmp = *stack;
	len = ft_ps_stacklen(*stack);
	indice = ps_smrtrot_target_a_bis(&tmp, &r_tmp, targ, len);
	if (indice == 0)
		return 0;
	else if (indice == 1)
		ft_ps_targetedrot(stack, m, tmp, "ra");
	else if (indice == -1)
		ft_ps_targetedrot(stack, m, r_tmp, "rra");
	return (1);
}
