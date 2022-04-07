/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvtbook_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:10:15 by lchan             #+#    #+#             */
/*   Updated: 2022/04/07 00:16:56 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_opt_cntnod(t_list *m, int *a, int *b)
{
	if (ft_strncmp("ra", (char *)m->content, 2))
	{
		while (m && ft_strncmp("ra", (char *)m->content, 2) == 0 && *a++)
			m = m->next;
		while (m && ft_strncmp("rb", (char *)m->content, 2) == 0 && *b++)
			m = m->next;
	}
	else if (ft_strncmp("rra", (char *)m->content, 3))
	{
		while (m && ft_strncmp("rra", (char *)m->content, 3) == 0 && *a++)
			m = m->next;
		while (m && ft_strncmp("rrb", (char *)m->content, 3) == 0 && *b++)
			m = m->next;
	}
	if (*b == 0)
		return (0);
	return (1);
}
/**********************************************************
 * first thing to know : a always rot before b during sort
 * cnt nbr of nod "ra"/"rra" then nbr not "rb"/"rrb"
 * if group of ra is followed by rb return (1)
 * ********************************************************/

void	ps_opt_cutnpatch_b(t_list **m, int a, int b)
{
	int	min;

	min = a;
	if (ft_strncmp("ra", m->content, 2) == 0)
	{
		while (min--)
		{
			m->content[1] = "r";
			if (min > 1)
				*m = (*m)->next;
		}
	}
	else 
	{
		while (min--)
		{
			(*m)->content[2] = "r";
			if (min > 1)
				(*m) = *m->next;
		}
	}
	ps_free_nod(m, b - a, a);
}
/*********************************************************
 * case nbr "rb"/"rrb" > nbr "ra"/"rra"
 * 		- turn rb into rr or rrb into rrr
 * 		- free all ra nod + repatch
 *		- m end up at nod after group of rb
 *********************************************************/

void	ps_opt_cutnpatch_a(t_list **m, int a, int b)
{
	int min;

	min = b;
	if (ft_strncmp("ra", m->content, 2) == 0)
	{
		while (min--)
		{
			m->content[1] = "r";
			if (min > 1)
				*m = (*m)->next;
		}
	}
	else 
	{
		while (min--)
		{
			(*m)->content[2] = "r";
			if (min > 1)
				(*m) = *m->next;
		}
	}
	ps_free_nod(m, a - b, b);
}
/*********************************************************
 * case more "ra"/"rra" than "rb"/"rrb"
 * 		- turn ra into rr or rra into rrr
 * 		- free all rb nod;
 * 		- repatch;
 *		- m end up at nod after group of rb
 *********************************************************/

void	ps_opt_cutnpatch_or_gonext(t_list **m)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (ps_opt_cntnbr(*m, &a, &b))
	{
		if (a > b)
			ps_opt_cutnpatch_a(m, a, b);
		else 
			ps_opt_cutnpatch_b(m, a, b);
	}
	else
		while (a-- > 0)
			*m = (*m)->next;
}
/*********************************************************
 * cut and patch if needed, or go next a times
 * *******************************************************/
void	ps_opt_mvtbook(t_list *m)
{
	int	a;
	int	b;

	while (m)
	{
		if (ft_strncmp("ra", (char *)m->content, 2) == 0
			|| ft_strncmp("rra", (char *)m->content, 2) == 0)
			 ps_opt_cutnpatch_or_gonext(&m);
		else 
			m = m->next;
	}
}
