/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:48:06 by lchan             #+#    #+#             */
/*   Updated: 2022/04/06 22:57:33 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lsub_goto_coordte(int *tab, t_stack **a, t_stack **b, t_list **m)
{
	int	x;
	int	y;

	x = tab[1];
	y = tab[2];
	if (x > 0)
		while (x--)
			ft_ps_rotate_a(a, m);
	else if (x < 0)
		while (x++)
			ft_ps_reverse_a(a, m);
	if (y > 0)
		while (y--)
			ft_ps_rotate_b(b, m);
	else if (y < 0)
		while (y++)
			ft_ps_reverse_b(b, m);
}
/*******************************************
 * rotate both stacks according to coordinate
 * *****************************************/

int	ps_lsub_findcheap(int **tab)
{
	int	i;
	int	j;
	int	min;

	i = -1;
	j = 0;
	while (tab[++i])
		if (tab[i][3] < tab[j][3])
			j = i;
	return (j);
}
/*******************************************
 * find cheapest elemt in cost_tab;
 *		returns its position;
 *******************************************/

int	ps_long_sub_pa(t_stack **a, t_stack **b, t_list **m)
{	
	int	**tab;
	int	*coord;

	while (*b)
	{
		tab = ps_cost_tab(*a, *b);
		if (!tab)
			return (0);
		coord = tab[ps_lsub_findcheap(tab)];
		ps_lsub_goto_coordte(coord, a, b, m);
		ft_ps_push_a(a, b, m);
		if ((*a)->rank > (*a)->next->rank)
			ft_ps_rotate_a(a, m);
	//	else if ((*a)->rank < (*a)->previous->rank)
	//		ft_ps_reverse_a(a, m);
		ps_tab_free(tab, ps_dtab_len(tab));
		tab = NULL;
	}
	return (1);
}
/********************************************************
 * In order : 
 * 		coord = tab[index of cheapest mvt]
 * 		mvt stack according to coord
 * 		if element is supposed to go at last position, rotate 
 * 		push_a according to best mvt
 * ******************************************************/

int	ps_long_sub_pb(t_stack **a, t_stack **b, t_list **m)
{
	int	*seq;
	int	len;
	int	i;
	int	j;

	seq = ps_longest_seq(*a, 1);
	if (!seq)
		return (0);
	len = ft_ps_stacklen(*a);
	i = -1;
	j = 0;
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
	return (1);
}
/********************************************************
 * generate seq (longest increasing subsequence sequence)
 * push_b anything not part of longest sub seq
 * ******************************************************/

int	ps_longsub_sort(t_stack **a, t_stack **b, t_list **m)
{
	if (!ps_long_sub_pb(a, b, m))
		return (0);
	if (!ps_long_sub_pa(a, b, m))
		return (0);
	return (1);
}
/*******************************
 * leave long sub in a, push rest in b;
 * use best cost to push back in b;
 * *****************************/
