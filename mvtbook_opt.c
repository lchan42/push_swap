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

int	ps_opt_m_ra(t_list *m)
{
	int	n;

	n = 0;
	while (m && ft_strncmp("ra", (char *)m->content, 2) == 0 && n++)
		m = m->next;
	if (m && ft_strncmp("rb", (char *)m->content, 2) == 0)
		return (0);
	else
		return (n);
}
/*********************************************
 * if group of ra is followed by rb return 0
 * else, return nbr of next I need to do;
 * *******************************************/


char	*ps_opt_mvtbook(t_list **m)
{
	int	n;

	while (m)
	{
		if (ft_strncmp("ra", (char *)m->content, 2) == 0)
		{
			n = ps_opt_m_ra(*m);
			if (!n)
			else
				while (n--)
					m = m->next;
		}
		m = m->next;
	}
}
