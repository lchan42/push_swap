/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/30 18:21:09 by lchan            ###   ########.fr       */
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

int	ft_ps_target_chklen(t_stack *head, int index)
{
	int	len;
	int	chklen;

	len = ft_ps_stacklen(head);
	chklen = 0;
	if (head->index == index)
		while (head->previous->index == index && len--)
			head = head->previous;
	else
	{
		while (head->index != index && len--)
			head = head->next;
		if (head->index != index)
			return (0);
	}
	return (ft_ps_chunck_len(head));
}
