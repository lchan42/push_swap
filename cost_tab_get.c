/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_tab_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:44:23 by lchan             #+#    #+#             */
/*   Updated: 2022/04/06 00:05:03 by lchan            ###   ########.fr       */
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

void	ps_cost_find_dst(int **dst, int **tab)
{
	int	i;
	int	j;
	int	len;

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
			else if (tab[i][0] > dst[len][0])
			{
				tab[i][1] = 0;
				break;
			}
		}
	}
}
/********************************
 * adding tab[ ][*][ ][ ]
 * 		find the correct dst;
 ********************************/


int	ps_cost_add_dst(t_stack *dst, int **tab , int opt)
{
	int	**dst_tab;
	int	len;

	len = ft_ps_chunck_len(dst);
	dst_tab = ps_tab_init(len);
	if (!dst_tab)
		return (0);
	ps_cost_add_rank_n_src(dst, dst_tab, len);
	ps_cost_find_dst(dst_tab, tab);
//	printf("------------------dst tab-------------------\n");
//	ps_printcost(dst_tab); //
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
	if (!ps_cost_add_dst(dst, tab, 1))
		return (NULL);
	ps_cost_add_cost(tab);
//	printf("------------------ STACK _B-------------------\n");
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
