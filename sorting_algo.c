/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:53:07 by lchan             #+#    #+#             */
/*   Updated: 2022/03/13 18:09:20 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ps_stacklen(t_stack *head)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	if (*head)
	{
		tmp = head->next;
		while (++len && tmp != head)
			tmp = tmp->next;
	}
	return (len);
}

int	ft_ps_findpivot(t_stack *head)
{
	t_stack	tmp;
	int		pivot;

	tmp = head->next;
	pivot = head->value;
	while (tmp != head)
	{
		pivot += tmp->value;
		tmp = tmp->next
	}
	return (pivot / ft_ps_stack_len(head));
}
/****************************************
 * returns the aritmetic average of a stack;
 */

int	ft_ps_chuckpivot (void)
{
	return (0);
}
	
int	ft_ps_sorted_checker(t_stack *head)
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
 * this function is checking if the list is sorted or not
 */

/***************************************************AFTER SICKNESS*******************************************/

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
/**************************************************
 * not sure it will be usefull;
 * this function was meant to check if a stack only needs rotation to be sorted.
 * it could be use for optimisation
 */

char	*ft_ps_findrotation(s_stack *head, int target)
{
	s_stack	tmp;
	int		cnt_rota;
	int		cnt_revrota;

	cnt_rota = 0;
	cnt_revrota = 0;
	tmp = head;
	while (tmp->rank != target && cnt_rota++)
		tmp = tmp->next;
	while (head->rank != target && cnt_revrota++)
		head = head->previous;
	if (cnt_rota > cnt_revrota++)
		return ("REVERSE");
	else if (cnt_rota < cnt_revrota)
		return ("NORMAL");
	return (NULL);
}
/***************************************************
 * this function returns a string that will tell us what rotation to use to reach the target.
 */

void	ft_ps_sort_five(s_stack **head)
{
	int		pivot;
	s_stack	tmp;

	if (!(*head) || ft_ps_sorted_checker(*head))
		return ;
	else if (is_circle_sorted(head))
		ft_ps_findrotation(s_stack *head, 1);
	else
		ft_ps_quicksort_a(head);
}

void	ft_ps_quicksort_a(s_stack **head)
{	
	int		pivot;
	int		len;
	
	pivot = ft_ps_findpivot(*head);
	len = ft_ps_stacklen(*head);
	while (--len)
	{
		if ((*head)->rank < pivot)
			push()

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
