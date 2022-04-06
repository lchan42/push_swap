/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_tab_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:44:23 by lchan             #+#    #+#             */
/*   Updated: 2022/04/06 22:35:37 by lchan            ###   ########.fr       */
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
 * 		add the dst to tab;
 ********************************/

int	**ps_cost_tab(t_stack *dst, t_stack *src)
{
	int	i;
	int	len;
	int	**tab;

	i = -1;
	len = ft_ps_chunck_len(src);
	tab = ps_tab_init(len);
	if (!tab)
		return (NULL);
	ps_cost_add_rank_n_src(src, tab, len);
	if (!ps_cost_add_dst(dst, tab, 1))
		return (NULL);
	while (tab[++i])
		tab[i][3] = ps_ab_val(tab[i][1]) + ps_ab_val(tab[i][2]);
//	ps_cost_add_cost(tab);
	return (tab);
}
/*************************************
 * in order
 * create tab[ ][ ][ ][ ]
 * adding tab[*][ ][*][ ] rank & src
 * adding tab[ ][*][ ][ ] dst
 * adding tab[ ][ ][ ][*] cost
 * tab is used and freed in ps_long_sub_pa
 *************************************/
