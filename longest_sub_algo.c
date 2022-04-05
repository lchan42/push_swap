/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:48:06 by lchan             #+#    #+#             */
/*   Updated: 2022/04/06 00:05:02 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_inc_or_decr(int *seq)
{
	int	len;

	len = ps_tab_len(seq);
	if (seq[0] > seq[len - 1])
		return (-1);
	if (seq[0] <= seq[len - 1])
		return (1);
	else
		return (0);
}

int	ps_lsub_findcheap(int **tab)
{
	int	i;
	int	min;

	i = -1;
	min = tab[0][3];
	while (tab[++i])
		if (tab[i][3] < min)
			min = tab[i][3];
	return (min);
}

void	ps_long_sub_pb(t_stack **a, t_stack **b, t_list **m)
{
	int	*seq;
	int	len;
	int	i;
	int	j;

	seq = ps_longest_seq(*a, 1);
	if (!seq)
		return ;
	len = ft_ps_stacklen(*a);
	i = -1;
	j = 0;
	ps_printseq(seq, len);
	while (++i < len)
	{
		if ((*a)->rank != seq[j])
			ft_ps_push_b(b, a, m);
		else
		{
			j++;
			ft_ps_rotate_a(a, m);
		}
	}
	free(seq);
}
/*******************************
 *
 * *****************************/

int	ps_longsub_sort(t_stack **a, t_stack **b, t_list **m)
{
	int	**tab;

	ps_long_sub_pb(a, b, m);
	tab = ps_cost_tab(*a,*b);
	if (!tab)
		return (0);
	printf("lowest cost = %d\n", ps_lsub_findcheap(tab));
	
	return (1);
}
/*******************************
 * leave long sub in a, push rest in b;
 *
 * *****************************/
