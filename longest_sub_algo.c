/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:48:06 by lchan             #+#    #+#             */
/*   Updated: 2022/04/05 19:22:36 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	m_push_a(t_stack **a, t_stack **b, t_list **m)
{
	if ((*b)->rank
}
*/
/*
int	ps_intchr(int n, int **tab) //might not be usefull
{
	int	i;
	int	len;

	i = -1;
	len = ps_tab_len(tab);
	while (++i < len)
		if (n == *tab[i])
			return (i);
	return (-1);
}

int	ps_find_seqposition(t_stack *dst, int **seq)//might not be usefull
{
	int	stk_len;
	int	result;

	stk_len = ft_ps_stacklen(dst);
	while (stk_len --)
	{
		result = ps_intchr(dst->rank, seq);
		if (result >= 0)
			return (result);		
		dst = dst->next;
	}
	return (-1);
}
*/
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

int	ps_reversable(t_stack *dst, t_stack *src, int seq)
{
	int	d_p;
	int	d;
	int	s;

	d_p = dst->previous->rank;
	d = dst->rank;
	s = src->rank;
	if (d_p < d && d_p > seq)
		return (1);
	return (0);
}
/*ce cas la va de paire avec pushrotable. Cas ou l.elemnt prevedant compris entre s et current*/
//a associer avec le mvt reverserotate

int ps_pushrotable(t_stack *dst, t_stack *src, int *seq, int i)
{
	int	tab_len;
	int	s;
	int	prev;

	tab_len = ps_tab_len(seq);
	s = src->rank;
	prev = dst->previous->rank;
	if (i < tab_len - 1 
		&& s < seq[i] && s < prev && s > seq[i + 1])
		return (1);
	return (0);
}
/****************** 
 * case : I have element before *seq[i]
 * 		that are seq[i] < element > seq[i + 1]
 * 		element > previous
 */

int	ps_push_swappable(t_stack *dst, t_stack *src, int *seq)
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
/*********************************
 * case : when we find element > *seq[i] after we pushed seq[i]
 * 		and between seq[i] and seq[i + 1];
 * apparently no need for i in the function.
 * 		the function only start to return 1 when at least 1 elem from new chk is pa.
*/

int	ps_rev_swappable(t_stack *dst, t_stack *src, int *seq, int i)
{
	if (src->rank == 80)
	{
			printf("src->next->ra ooajfihFGnk = %d\n", src->next->rank);
		if (ps_pushrotable(dst, src, seq, i))
			printf("ok reversable 1\n");
		if (ps_pushrotable(dst, src->next, seq, i))	
			printf("ok reversable 2\n");
		if (src->rank < src->next->rank)
			printf("ok reversable 3\n");
			return (1);
	}
	return (0);
}

void	ps_longsub_exec_a(t_stack **a, t_stack **b, t_list **m, int *seq, int i)
{
	if (ps_push_swappable(*a, *b, seq))//element were before
	{
		printf("inside push_swappable\n");
		printf("pushing %d\n", (*b)->rank);
		ft_ps_push_a(a, b, m);
		printf("swapping %d & %d\n", (*a)->rank, (*a)->next->rank);
		ft_ps_swap_a(a, m);
		printf("inside push_swappable\n");
	}
	else if (ps_rev_swappable(*a, *b, seq, i))
	{
		printf("inside rev_swapable\n");
		ft_ps_swap_b(b, m);
	}
	else if (ps_pushrotable(*a, *b, seq, i)) //element is after
	{
		printf("inside push_rotable\n");
		ft_ps_push_a(a, b, m);
		ft_ps_rotate_a(a, m);
	}

	else if (ps_reversable(*a, *b, seq[i])) // element is after
	{
		printf("inside reversable\n");
		ft_ps_reverse_a(a, m);
	}
//	else if (ps_pushable(*a, *b))// element is now; 
		
	else
		ft_ps_rotate_b(b, m);	
}//a = dst

void	ps_longsub_pa(t_stack **a, t_stack **b, t_list **m, int seq)
{
	if ((*a)->rank > (*b)->next->rank && (*b)->rank > seq)
	{
		ft_ps_swap_b(b, m);
		ft_ps_push_a(a, b, m);
	}
	ft_ps_push_a(a, b, m);
}
// case : src->next is between tab[i] and dst. In this case we swap 

void	ps_long_sub_pa(t_stack **a, t_stack **b, t_list **m)
{
	int	*seq;
	int	len;
	int	i;

	seq = ps_longest_seq(*b, -1);
	if (!seq)
		return ;
	len = ps_tab_len(seq);
	i = 0;
	ps_printseq(seq, len);
	while (i < len )
	{
		if ((*b)->rank == seq[i])
		{
			ps_longsub_pa(a, b, m, seq[i]);
			i++;
		}
		else
			ps_longsub_exec_a(a, b, m, seq, i);
	}
	free(seq);
}

/*
void	ps_long_sub_pa(t_stack **a, t_stack **b, t_list **m)
{
	int	**seq;
	int	len;
	int	i;

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
	//	if (i > 0 && ps_swappable(*a, *b, seq, i))

	}
	free(seq);
}*/
