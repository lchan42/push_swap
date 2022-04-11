/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:51:30 by lchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:48:12 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exit_error(t_stack **a, t_stack **b, t_list **m, int exitcode)
{
	if (a)
		ps_free_t_stack(a);
	if (b)
		ps_free_t_stack(b);
	if (m)
		ps_free_tlist(m);
	ft_putstr_fd("ERROR\n", 2);
	exit(exitcode);
}


