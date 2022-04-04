/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:26:32 by lchan             #+#    #+#             */
/*   Updated: 2022/04/04 21:24:10 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_tab_free(int **tab, int len)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (++i < len)
			if (tab[i])
				free(tab[i]);
		free(tab);
	}
}

int	**ps_tab_init(int len)
{
	int	**tab;
	int	i;

	i = -1;
	tab = (int **)malloc((len + 1) * sizeof(int *));
	if (!tab)
		return (NULL);
	while (++i < len)
	{
		tab[i] = (int *)malloc(2 * sizeof(int));
		if (!tab[i])
		{
			ps_tab_free(tab, len);
			tab = NULL;
			break ;
		}
	}
	tab[len] = NULL;
	return (tab);
}

void	ps_tab_add_pot(int **tab, int len, int opt)
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

int **ps_tab_create(t_stack *stk, int len, int opt)
{
	int	**tab;
	int	i;

	tab = ps_tab_init(len);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		tab[i][0] = stk->rank;
		stk = stk->next;
	}
	tab[i] = 0;
	ps_tab_add_pot(tab, len, opt);
	return (tab);
}

int ps_tab_len(int **tab)
{
	int	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}













/*****************delete afterwards*****************/

int	ps_tab_nxtlow (int **tab, int i, int uplmt) // not sure I'll use it
{
	int	len;
	int	l;
	int	max;

	len = ps_tab_len(tab);
	l = *tab[uplmt];
	max = -1;
	while (tab[i])
	{
		if (*tab[i] < l)
		{
			max = i;
			break;
		}
		i++;
	}
	while (i < len && tab[++i] && max != -1)
		if ( *tab[max] < *tab[i] && *tab[i] < l)
			max = i;
	return (max);
}

void	ps_printtab(int **tab)
{
	int	i;

	if (!tab)
		return;
	i = -1;
	printf("---{copied tab :}--- \n");
	while (tab[++i] != 0)
	{
		printf("    tab[%2d] = %d ", i, tab[i][0]);
		printf("    pot = %d\n", tab[i][1]);
	}
	printf("\n");
}

void	ps_printseq(int	*tab, int len)
{
	int	i;

	i = -1;
	printf("---{LDS :}--- \n");
	while (++i < np)
		printf("    tab[%2d] = %d\n ", i, tab[i]);
	
}
