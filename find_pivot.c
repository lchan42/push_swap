/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/27 18:34:34 by lchan            ###   ########.fr       */
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

int	ft_ps_chunckpivot(t_stack *head)
{
	t_stack	*tmp;
	int		pivot;
	int 	chunck_len;
	int		len_tmp;

	tmp = head;
	pivot = 0;
	chunck_len = ft_ps_chunck_len(head);
	len_tmp = chunck_len;
	while (len_tmp--)
	{
		pivot += tmp->rank;
		tmp = tmp->next;
	}
	pivot /= chunck_len;
	return (pivot);
}

int	ft_ps_targeted_chunckpivot(t_stack *head, int index)
{
	int	len;

	len = ft_ps_stacklen(head);
	if (head->index == index)
		while (head->previous->index == index)
			head = head->previous;
	else
		while (len--)
		{
			head = head->next;
			if (head->index == index)
				break ;
		}
	return (ft_ps_chunckpivot(head));
}
