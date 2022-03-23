/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/23 16:35:15 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_stacklen(t_stack *head)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	if (head)
	{
		tmp = head->next;
		while (++len && tmp != head)
			tmp = tmp->next;
	}
	return (len);
}

int	ft_ps_chunck_len(t_stack *head)
{
	t_stack	*tmp;
	int		chunck;
	int		len;

	if (head)
	{
		tmp = head->next;
		chunck = head->index;
		len = 1;
		while (tmp != head && tmp->index == chunck && ++len)
			tmp = tmp->next;
	}
	return (len);
}

int	ft_ps_chunckmax_len(t_stack *head)
{
	t_stack	*tmp;
	int		chunck;
	int		len;
	int		max_len;

	tmp = head;
	max_len = 0;
	if (head)
	{
		while (tmp->next != head)
		{
			chunck = tmp->index;
			len = 0;
			while (tmp->next != head && tmp->index == chunck)
			{
				len++;
				tmp = tmp->next;
			}
			if (len > max_len)
				max_len = len;
		}
	}
	return (max_len);
}
