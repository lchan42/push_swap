/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sub_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:26:32 by lchan             #+#    #+#             */
/*   Updated: 2022/03/31 17:45:51 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//longest_subequence_utils.c
int **ps_chunck_cpy(t_stack *stk, int len)
{
	int	**tab;
	int	i;

	tab = (int **)malloc((len + 1) * sizeof(int*));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		tab[i] = &(stk->rank);
		stk = stk->next;
	}
	tab[i] = 0;
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

void	ps_printtab(int **tab)
{
	int	i;

	i = -1;
	printf("---{copied tab :}--- \n");
	while (tab[++i] != 0)
		printf("    tab[%2d] = %d\n", i, tab[i][0]);
	printf("\n");
}
