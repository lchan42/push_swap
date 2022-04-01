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

int	ps_inc_or_decr(int **seq)
{
	int	len;

	len = ps_tab_len(seq)
	if (*seq[0] > seq[len])
		return (-1)
	if (*seq[0]) =< seq[len]
		return (1)
}

int	ps_rotable(t_stack *dst, t_stack *src)
{
	int	prev;
	int	curr;

	prev = dst->previous->rank;
	curr = dst->rank;
	if (prev > s && prev < dst->rank)
		return (1);
}
/*ce cas la va de paire avec pushrotable. Cas ou l.elemnt prevedant compris entre s et current*/
//a associer avec le mvt reverserotate
int ps_pushrotable(t_stack *dst, t_stack *src, int seq) // il faut envoyer seq[i] a chaque fois
{
	int	prev;
	int curr;
	int	s;
	int	way;

	if (!dst)
		return (0);
	prev = dst->previous->rank;
	curr = dst->rank;
	s = src->rank;
	way = ps_inc_or_decr(seq);
	if (way < 0 && s > curr && s < prev)
		return (1);
	else if (way > 0 && s < curr && s > prev)
		return (1);
	else
		return (0);
}
//cas ou l element 80 ( et 77) et compris entre 85 et 81, 
//ou cas ou les element 77 73 76 est compris avant 85 ? que faire ? --> function magic push ? 

int	ps_swappable(t_stack *dst, t_stack *src, int **seq)
{
	int	next;
	int curr;
	int	s;
	int	way;

	if (!dst) // ou *dst ? demander a adrien
		return (0);
	next = dst->next->rank;
	curr = dst->rank;
	s = src->rank;
	way = ps_inc_or_decr(seq);
	if (way < 0 && s > curr && s < next)
		return (1);
	else if (way > 0 && s < curr && s > next)
		return (1);
	else
		return (0);
}

int	ps_swappable_intra_stk(t_stack *src, int **seq, int i)
// it be arriver que l element stack->rank apres ce lui correspondant a tab[i] soit compris entre tab[i] et tab[i - 1] dans ce cas, ca vaut peut etre le coup de swap;

void	ps_long_sub_pa(t_stack **a, t_stack **b, t_list **m)
{
	int	index;
	int	**seq;
	int	len;
	int	i;

	index = (*b)->index;
	seq = ps_longest_seq(*b, -1);
	if (!seq)
		return ;
	len = ps_tab_len(seq);
	i = 0;
//	ps_printtab(seq);
	while (i < len )
	{
		if ((*b)->rank == *seq[i])
		{
			ft_ps_push_a(a, b, m);
			i++;
		}
		else
			ft_ps_rotate_b(b, m);
		if (i > 0 && ps_inc_swappable(*a, *b, seq, i))

	}
	free(seq);
}
