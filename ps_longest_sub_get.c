/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_longest_sub_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:26:32 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 18:58:01 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_tab_goto_nextpot_decr(int **tab, int len, int curr)
{
	int	np;
	int i;

	np = len;
	i = curr;
	if (curr < 0)
	{
		np = 0;
		while (++i < len)
			if (tab[i][1] > tab[np][1])
				np = i;
		return (np);
	}
	while (++i < len)
	{
		if (tab[i][0] < tab[curr][0])
		{
			if (!tab[np])
				np = i;
			else if (tab[np] && tab[i][1] >= tab[np][1])
				np = i;
		}
	}
	return (np);
}

int	ps_tab_goto_nextpot_incr(int **tab, int len, int curr)
{
	int	np;
	int i;

	np = len;
	i = curr;
	if (curr < 0)
	{
		np = 0;
		while (++i < len)
			if (tab[i][1] > tab[np][1])
				np = i;
		return (np);
	}
	while (++i < len)
	{
		if (tab[i][0] > tab[curr][0])
		{
			if (!tab[np])
				np = i;
			else if (tab[np] && tab[i][1] >= tab[np][1])
				np = i;
		}
	}
	return (np);
}
/***********************************************
 * if curr = -1, find highers potential
 * if curr > -1, find next high after tab[curr]
 ***********************************************/

void	ps_tab_add_pot(int **tab, int opt)
{
	int i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		tab[i][1] = 0;
		j = i;
		if (opt < 0)
		{
			while (tab[++j])
				if (*tab[j] < *tab[i])
					tab[i][1]++;
		}
		else if (opt >= 0)
		{
			while (tab[++j])
				if (*tab[j] > *tab[i])
					tab[i][1]++;
		}
	}
}
/***************************************
 * add potential to tab[i][1];
 * *************************************/

int	*ps_tab_select_lgsub(int **tab, int len, int opt)
{
	int	*seq;
	int	i;
	int np;

	i = -1;
	np = ps_tab_goto_nextpot_decr(tab, len, i);
	if (opt >= 0)
		np = ps_tab_goto_nextpot_incr(tab, len, i);
	seq = (int *)malloc((tab[np][1] + 2) * sizeof (int));
	if (!seq)
		return (NULL);
	seq[++i] = tab[np][0];
	while (np != len)
	{
		if (opt == -1)
			np = ps_tab_goto_nextpot_decr(tab, len, np);
		else
			np = ps_tab_goto_nextpot_incr(tab, len, np);
		if (np == len)
			break;
		seq[++i] = tab[np][0];
	}
	seq[++i] = 0;
	return (seq);
}
/***********************************************
 * creat longest subseq
 ***********************************************/

int	*ps_longest_seq(t_stack *stk, int opt)
{
	int	len;
	int	**tab;
	int	*seq;

	len = ft_ps_chunck_len(stk);
	if (len <= 1)
		return NULL;
	tab = ps_tab_create(stk, len);
	if (!tab)
		return (NULL);
	ps_tab_add_pot(tab, opt);
	seq = ps_tab_select_lgsub(tab, len, opt);
	ps_tab_free(tab);
	return (seq);
}
/***********************************************
 * if opt = -1, return decreasing sub sequence
 * if opt >= 0, return increasing sub sequence
 * seq is used and freed in ps_long_sub_pb (longest_sub_algo.c)
 * *********************************************/
