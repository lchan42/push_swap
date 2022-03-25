/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/25 15:25:51 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_pivot_mark(t_stack *head, int pivot) //might not be usefull ?? 
{
	int	intern_pivot;
	int	chunck_len;
	int	sub_pivot;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_len = ft_ps_chunck_len(head);
	sub_pivot = ft_ps_subpivot(head, pivot);
	while (chunck_len--)
	{
		if (head->rank < intern_pivot)
			head->index = sub_pivot;
//		else
//			head->index = pivot + 1;
		head = head->next;
	}
}

int		ft_ps_intern_pivot(int chunck_len, int pivot)
{
	if (ft_ps_is_even_nbr(chunck_len))
		return (pivot + 1);
	return (pivot);
}

int	ft_ps_subpivot(t_stack *head, int pivot) //calculate in advance a pivot into a pivot group;
{
	int	intern_pivot;
	int	chunck_len;
	int	sub_len;
	int	sub_pivot;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_len = ft_ps_chunck_len(head);
	sub_len = 0;
	sub_pivot = 0;
	while (chunck_len--)
	{
		if (head->rank < intern_pivot && ++sub_len)
			sub_pivot += head->rank;
		head = head->next;
	}
	if (sub_pivot == 0 || sub_len == 0)
		return (0);
	return (sub_pivot/sub_len);
}

int	ft_ps_count_underpivot(t_stack *head, int pivot) //for stack_a
{
	int	intern_pivot;
	int	chunck_index;
	int	chunck_len;
	int	count;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_index = head->index;
	chunck_len = ft_ps_chunck_len(head);
	count = 0;
	while (head->index == chunck_index && chunck_len--)
	{
		if (head->rank < intern_pivot)
			count++;
		head = head->next;
	}
	return (count);
}

int	ft_ps_count_overpivot(t_stack *head, int pivot) //for stack_b (count number of element over pivot)
{
	int	intern_pivot;
	int	chunck_index;
	int	chunck_len;
	int	count;

	intern_pivot = ft_ps_intern_pivot(ft_ps_chunck_len(head), pivot);
	chunck_index = head->index;
	chunck_len = ft_ps_chunck_len(head);
	count = 0;
	while (head->index == chunck_index && chunck_len--)
	{
		if (head->rank >= intern_pivot)
			count++;
		head = head->next;
	}
	return (count);
}
