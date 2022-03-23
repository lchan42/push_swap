/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/23 16:36:53 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
