/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/23 22:20:18 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_ps_sorted_checker_a_n(t_stack *head, int n)
{
	t_stack	*tmp;
	int		i;

	tmp = head->next;
	i = 0;
	while  (++i && --n)
	{
		if (tmp->rank != head->rank + i)
		{
//			printf("not sorted tmp->rank = %d i = %d\n", tmp->rank, i);
			return (0);
		}
//		printf("tmp->rank(%d) = head->rank + i (%d)\n", tmp->rank, i);
		tmp = tmp->next;
	}
	return (1);
}

/******************************************************
 * check if n element are sorted
 * */

int	ft_ps_sorted_checker_b_n(t_stack *head, int n)
{
	t_stack	*tmp;
	int		i;

	tmp = head->next;
	i = 0;
	while  (++i && n--)
	{
		if (head->rank != tmp->rank + i)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


/***************************************************AFTER SICKNESS*******************************************/
int	ft_ps_is_sorted(t_stack *head)
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
