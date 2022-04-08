/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 16:00:05 by lchan            ###   ########.fr       */
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
	pivot = pivot / ft_ps_stacklen(head);
	return (pivot);
}

int		ft_ps_intern_pivot_a(int chunck_len, int pivot)
{
	if (ft_ps_is_even_nbr(chunck_len))
		return (pivot + 1);
	return (pivot);
}
