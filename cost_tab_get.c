/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_tab_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:44:23 by lchan             #+#    #+#             */
/*   Updated: 2022/04/06 18:30:44 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_cost_add_rank_n_src(t_stack *src, int **tab, int len)
{
	int	i;
	int	j;
	int	*middle;

	i = -1;
	j = -1;
	while (++i < len / 2)
		tab[i][2] = ++j;
	tab[i][2] = ++j;
	middle = tab[i];
	i = len;
	j = -1;
	while (tab[--i] != middle)
		tab[i][2] = j--;
	i = -1;
	while (++i < len)
	{
		tab[i][0] = src->rank;
		src = src->next;
	}
}
/********************************
 * adding tab[*][ ][*][ ]
 * 		adding the rank;
 * 		and position in the tab;
 ********************************/

int	ps_cost_findmax_rk(int	**dst)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (dst[++i])
		if (dst[i][0] > dst[max][0])
			max = i;
	return (max);
}
/*********************************
 * adding tab[ ][*][ ][ ]
 * find the maximum value in dst
 * *******************************/

int	ps_cost_find_closest(int **dst, int *tab)
{
	int	i;
	int	result;
	int	max;
	int	len;

	i = -1;
	result = i;
	max = ps_cost_findmax_rk(dst);
	len = ps_dtab_len(dst) -1;
	if (tab[0] < *dst[max])
	{
		while (dst[++i])
			if (*dst[i] > tab[0]
				&& (result == -1 || *dst[i] - tab[0] < *dst[result] - tab[0]))
					result = i;
	}
	else 
	{
		if (max == len)
			result  = 0;
		else
			result = max + 1;
	}
	return (result);
}
/********************************
 * adding tab[ ][*][ ][ ]
 * 		find the correct dst index;
 ********************************/

/* 
void	ps_cost_find_dst(int **dst, int **tab)
{
	int	i;
	int	j;
	int	len;
	int	max;

	i = -1;
	max = 0;
	while (dst[++i])
		if (dst[i][0] > dst[max][0])
			max = i;
	i = -1;
	len = ps_dtab_len(dst) - 1;
	while (tab[++i])
	{
		j = -1;;
		while (dst[++j])
		{
			if (tab[i][0] < dst[j][0])
			{
				tab[i][1] = dst[j][2];
				break;
			}
			else if (tab[i][0] > dst[max][0])////
			{
				if (max == len)
					tab[i][1] = 0;
				else
					tab[i][1] = dst[max + 1][2];
				break;
			}
		}
	}
}*/

/********************************
 * adding tab[ ][*][ ][ ]
 * 		find the correct dst;
 ********************************/

int	ps_cost_add_dst(t_stack *dst, int **tab , int opt)
{
	int	**dst_tab;
	int	len;
	int	c;
	int	i;
	
	len = ft_ps_chunck_len(dst);
	dst_tab = ps_tab_init(len);
	i = -1;
	if (!dst_tab)
		return (0);
	ps_cost_add_rank_n_src(dst, dst_tab, len);
	printf("------------------dst tab-------------------\n");//
	ps_printcost(dst_tab); //
	//ps_cost_find_dst(dst_tab, tab);
	while (tab[++i])
	{
		c = ps_cost_find_closest(dst_tab, tab[i]);
		tab[i][1] = dst_tab[c][2];
	}
	ps_tab_free(dst_tab, len);
	return (1);
}
/********************************
 * adding tab[ ][*][ ][ ]
 * 		adding the dst;
 ********************************/

void	ps_cost_add_cost(int **tab)
{
	int	i;
	int	cost;

	i = -1;
	while (tab[++i])
		tab[i][3] = ps_ab_val(tab[i][1]) + ps_ab_val(tab[i][2]);
}
/********************************
 * adding tab[ ][ ][ ][*]
 * 		adding the cost;
 ********************************/

int	**ps_cost_tab(t_stack *dst, t_stack *src)
{
	int	len;
	int	**tab;

	len = ft_ps_chunck_len(src);
	tab = ps_tab_init(len);
	if (!tab)
		return (NULL);
	ps_cost_add_rank_n_src(src, tab, len);
//	printf("------------------ CT after add rank_n_src-------------------\n");//
//	ps_printcost(tab);//
	if (!ps_cost_add_dst(dst, tab, 1))
		return (NULL);
//	printf("------------------ CT after add dst-------------------\n");//
//	ps_printcost(tab);//
	ps_cost_add_cost(tab);
//	printf("------------------ CT after add cost-------------------\n");//
//	ps_printcost(tab);//
	printf("------------------ src tab -------------------\n");//
	ps_printcost(tab);//
//	ps_tab_free(tab, len);//
//	tab = NULL;//
	return (tab);
}
/*************************************
 * in order
 * create tab[ ][ ][ ][ ]
 * adding tab[*][ ][*][ ] rank & src
 * adding tab[ ][*][ ][ ] dst
 * adding tab[ ][ ][ ][*] cost
 *************************************/
