/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_cost_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:07:17 by lchan             #+#    #+#             */
/*   Updated: 2022/04/07 21:24:18 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_opt_getminval(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

int	**ps_opt_costtab(int **tab)
{
	int	i;
	int	x;
	int	y;
	int	min;

	i = -1;
	while (tab[++i])
	{
		x = tab[i][1];
		y = tab[i][2];
		if ((x > 0 && y > 0) || (x < 0 && y < 0))
		{
			min = ps_opt_getminval(ps_ab_val(x), ps_ab_val(y));
			tab[i][3] -= min;
		}
	}
	return (tab);
}
