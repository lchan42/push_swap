/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:26:32 by lchan             #+#    #+#             */
/*   Updated: 2022/03/31 18:04:33 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**ps_cpylower(int **tab, int current, int start, int len)
{
	int	i;
	int	**seq;

	i = 0;
	seq = (int **)malloc((len + 1) * sizeof(int *));
	if (!seq)
		return (NULL);
	seq[i] = tab[current];
	while (tab[start])
	{
		if (*tab[start] < *seq[i])
			seq[++i] = tab[start];
		start++;
	}

	seq[++i] = NULL;
	return (seq);
}

int **ps_decr_seq(int **tab, int len)
{
	int	i;
	int	j;
	int	**tmp;
	int	**seq;

	i = -1;
	seq = NULL;
	while (tab[++i])
	{
		j = i + 1;
		while (tab[j])
		{
			tmp = ps_cpylower(tab, i, j, len);
			if (ps_tab_len(tmp) > ps_tab_len(seq))
			{
				if (seq)
					free(seq);
				seq = tmp;
			}
			j++;
		}
	}
	if (tmp)
		free(tmp);
	return (seq);
}

int	**ps_cpyhigher(int **tab, int current, int start, int len)
{
	int	i;
	int	**seq;

	i = 0;
	seq = (int **)malloc((len + 1) * sizeof(int *));
	if (!seq)
		return (NULL);
	seq[i] = tab[current];
	while (tab[start])
	{
		if (*tab[start] > *seq[i])
			seq[++i] = tab[start];
		start++;
	}

	seq[++i] = NULL;
	return (seq);
}

int **ps_incr_seq(int **tab, int len)
{
	int	i;
	int	j;
	int	**tmp;
	int	**seq;

	i = -1;
	seq = NULL;
	while (tab[++i])
	{
		j = i + 1;
		while (tab[j])
		{
			tmp = ps_cpyhigher(tab, i, j, len);
			if (ps_tab_len(tmp) > ps_tab_len(seq))
			{
				if (seq)
					free(seq);
				seq = tmp;
			}
			j++;
		}
	}
	if (tmp)
		free(tmp);
	return (seq);
}

int	**ps_longest_seq(t_stack *stk, int opt)
{
	int	len;
	int	**tab;
	int	**seq;

	len = ft_ps_chunck_len(stk);
	tab = ps_chunck_cpy(stk, len);	
	if (!tab)
		return (NULL);
	if (opt >= 0)
		seq = ps_incr_seq(tab, len);
	else if (opt < 0)
		seq = ps_decr_seq(tab, len);
//	ps_printtab(tab);	
//	ps_printtab(seq);
	free (tab);
	return (seq);
}
