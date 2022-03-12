/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/12 23:02:00 by lchan            ###   ########.fr       */
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
/****************************************
 * this function is using a pivot of half the list
 * it's returning the address of the pivot;
 */

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
 * this function is checking if the function is sorted or not
 */

/***************************************************AFTER SICKNESS*******************************************/
void	ft_ps_pick_rotation(s_stack **head)
{
	if ()
		reserse_rotate 
	else
		rotate(head_a, NULL);
}

int	is_circle_sorted(s_stack *head)
{
	while (head->rank != 1)
		head = head->next;
	while (head->next->rank != 1)
	{
		if (head->next->rank != head->rank + 1)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_ps_sort_five(s_stack **head)
{
	if (!(*head) || is_circle_sorted(*head))
		return ;
	while (1)
	{
		if ((*head)->next->rank > (*head)->rank)
			swap(**head);
		if (!is_circle_sorted(*head)) 
			ft_ps_pick_rotation(s_stack **head);
		else
			break ;
	}
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
