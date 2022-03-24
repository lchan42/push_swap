/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/24 17:49:58 by lchan            ###   ########.fr       */
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
//	if (!ft_ps_is_even_nbr(pivot))
//		pivot--;
	return (pivot);
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

/*  THIS FUNCTION MIGHT BE BETTER BUT HASNT BEEN TESTED YET
int	ft_ps_chunckpivot(t_stack *head)
{
	t_stack	*tmp;
	int		pivot;
	int 	chunck_len;
	int		len_tmp;

	tmp = head->next;
	pivot = 0;
	chunck_len = ft_ps_chunck_len(head);
	len_tmp = chunck_len;
	while (len_tmp--)
	{
		pivot += tmp->rank;
		tmp = tmp->next;
	}
	pivot /= chunck_len;
//	if (!ft_ps_is_even_nbr(pivot))
//		pivot--;
	return (pivot);
}
*/
