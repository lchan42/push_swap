/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_buildstack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:58:49 by lchan             #+#    #+#             */
/*   Updated: 2022/02/25 15:21:49 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_addback(t_stack **head)
{

}

t_stack	*nod_init(int value)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack))
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->rank = 0;
	tmp->next = NULL;
	return (tmp);
}

t_stack	

t_stack	*build_stack(int ac, char **av)
{
	t_stack		*stack_a
	
	t_stack = malloc(sizeof(t_stack));

	while ()
}
