/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:42:10 by lchan             #+#    #+#             */
/*   Updated: 2022/04/12 22:37:03 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_emergencyfree_list(t_stack *head)
{
	t_stack *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	exit(BUILDSTACK_ERROR);
}
/****************************************
 * used to protect nod init in buildstack
 * **************************************/

t_list **ps_free_tlist_nod(t_list **m, int skip, int nbr)
{
	t_list	*cut;
	t_list	*tmp;

	while (skip--)
		*m = (*m)->next;
	cut = (*m);
	*m = (*m)->next;
	while (nbr--)
	{
		tmp = *m;
		*m = (*m)->next;
		free(tmp);
	}
	cut->next = *m;
	return (m);
}
/*********************************************************************
 * used in ps_opt_cutnpatch_a / _b
 * skip nod; (deals with remaining ra or rb)
 * free nbr nods of rb;
 * repatch nods;
 * ps : no need for free(tmp->content) coz content hasnt been malloced
 *********************************************************************/

void	ps_free_tlist(t_list **m)
{
	t_list	*tmp;

	while (*m)
	{
		tmp = *m;
		*m = (*m)->next;
		free(tmp);
	}
	*m = NULL;
}

void	ps_free_t_stack(t_stack **a)
{
	t_stack *tmp;
	
	if (!*a)
		return ;
	(*a)->previous->next = NULL;
	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		if (tmp)
			free(tmp);
		tmp = NULL;
	}
	*a = NULL;
}
/******************************************
 * making the list non circular before free
 * ****************************************/

void	ps_free_env(t_stack **a, t_stack **b, t_list **m)
{
	if (*a)
		ps_free_t_stack(a);
	if (*b)
		ps_free_t_stack(b);
	if (*m)
		ps_free_tlist(m);
}
