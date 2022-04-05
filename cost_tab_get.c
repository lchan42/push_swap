/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_tab_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:44:23 by lchan             #+#    #+#             */
/*   Updated: 2022/04/05 21:11:23 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




void	ps_cost_add_srcpos(t_stack *src, int **tab, int len)
{
	int	i;
	int	j;
	int	*middle;

	i = -1;
	j = -1;
	while (++i < len / 2)
		tab[i][1] = ++j;
	if (ft_ps_is_even_nbr(len))
		tab[i][1] = ++j;
	middle = tab[i];
	i = len;
	j = -1;
	while (tab[--i] != middle)
		tab[i][1] = j--;
}

void	ps_cost_add_rank(t_stack *src, int **tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		tab[i][0] = src->rank;
		src = src->next;
	}
}

int	**ps_cost_add_dst(t_stack *dst, int **tab , int opt)
{
	int	**dst_tab;
	int	len;

	len = ft_ps_chunck_len(dst);
	dst_tab = ps_tab_init(len);
	if (!dst_tab)
		return NULL;
	ps_cost_add_rank(dst, dst_tab, len);
	ps_cost_add_srcpos(dst, dst_tab, len);
	ps_printcost(dst_tab);
	ps_tab_free(dst_tab, len);
	return (NULL);
}

int	**ps_cost_tab(t_stack *dst, t_stack *src)
{
	int	**tab;
	int	len;

	len = ft_ps_chunck_len(src);
	tab = ps_tab_init(len);
	if (!tab)
		return (NULL);
	ps_cost_add_srcpos(src, tab, len);
	ps_cost_add_rank(src, tab, len);
	ps_printcost(tab);
	ps_cost_add_dst(dst->next, tab, 1);
	ps_tab_free(tab, len);
	tab = NULL;
	return (tab);
}
