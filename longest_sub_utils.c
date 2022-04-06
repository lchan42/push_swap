/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:26:32 by lchan             #+#    #+#             */
/*   Updated: 2022/04/06 23:09:27 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_tab_free(int **tab, int len)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i]) //< len)
	//		if (tab[i])
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
		tab[i] = (int *)malloc(4 * sizeof(int));
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
/***************************************************
 * used and freed multiple times
 * 		in ps_long_sub_pa
 * 		used to get the cost table
 * *************************************************/

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
/****************************************
 * used and freed in ps_longest_seq;
 * provide tab of potential to creat longest seq;
 * **************************************/

int ps_tab_len(int *tab)
{
	int	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}

int	ps_dtab_len(int **tab)
{
	int	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}










/*****************delete afterwards*****************/

void	ps_printtab(int **tab)
{
	int	i;

	if (!tab)
		return;
	i = -1;
	printf("---{copied tab :}--- \n");
	while (tab[++i] != 0)
	{
		printf("tab[%2d] = %d ", i, tab[i][0]);
		printf("pot = %d\n", tab[i][1]);
	}
	printf("\n");
}

void	ps_printseq(int	*tab, int len)
{
	int	i;

	i = -1;
	printf("------------------{LDS :}------------------- \n");
	while (++i < len && tab[i])
		printf("tab[%2d] = %d\n", i, tab[i]);
	printf("\n");	
}

void	ps_printcost (int **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("tab[%2d] :  %3d	%3d	%3d	%3d\n", i, tab[i][0], tab[i][1], tab[i][2], tab[i][3]);
	printf("\n");	
}
