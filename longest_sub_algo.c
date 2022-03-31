/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:48:06 by lchan             #+#    #+#             */
/*   Updated: 2022/03/31 18:32:38 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	m_push_a(t_stack **a, t_stack **b, t_list **m)
{
	if ((*b)->rank
}
*/
void	long_sub_pa(t_stack **a, t_stack **b, t_list **m)
{
	int	index;
	int	**seq;
	int	len;
	int	i;

	index = (*b)->index;
	seq = ps_longest_seq(*b, -1);
	len = ps_tab_len(seq);
	i = 0;
	ps_printtab(seq);
	while (i < len )
	{
		if ((*b)->rank == *seq[i])
		{
			ft_ps_push_a(a, b, m);
			i++;
		}
		else
			ft_ps_rotate_b(b, m);
	}
	free(seq);
}
