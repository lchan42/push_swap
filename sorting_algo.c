/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/05 15:33:16 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ps_clst_len(t_list *head)
{
	int		len;
	t_list	*tmp;

	len = 0;
	if (*head)
	{
		tmp = head->next;
		while (++len && tmp != head)
			tmp = tmp->next;
	}
	return (len);
}

t_stack	*ft_ps_find_pivot(t_list *head)
{
	int	pivot;

	pivot = ft_ps_clst_len(head) / 2;
	while (head)
	{
		if (head->rank == pivot)
			return (head);
		head = head->next;
	}
}

int	ft_ps_sorted_checker(t_list *head)
{
	int		len;
	t_list	tmp;

	len = ft_ps_clst_len(head);
	tmp = head;
	while (tmp->next != head)
	{
		if (tmp->rank != tmp->next->rank + 1)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->rank = len)
		return (1);
	return (0);
}

/*********************************************
 * condition de backtracking
 * 		stack b empty, stack a has all the different digit
 *		rank of stack a are following each other
 *
 *
 *	other
 *	 
 *		cost compilator and cost comparator;
