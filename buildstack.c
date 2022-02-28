/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_buildstack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:58:49 by lchan             #+#    #+#             */
/*   Updated: 2022/02/28 19:51:32 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_free_list(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void	ft_ps_free_list(t_stack **head)
{
	t_stack	*tmp;
	t_stack 


	tmp = NULL;
	while (tmp != *head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
t_stack	*ft_ps_nod_init(int value, int index)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->rank = 0;
	tmp->index = index;
	tmp->previous = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*ft_ps_stack_new_addback(t_stack **head, int value, int index)
{
	t_stack	*tmp;

	tmp = *head;
	if (!*head)
		*head = ft_ps_nod_init(value, index);
else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_ps_nod_init(value, index);
		if (!tmp->next)
			ft_ps_free_list(head);
		tmp->next->previous = tmp;
		(*head)->previous = tmp->next;
	}
	return (*head);
}
/*********************************************************
 * if ft_ps_nod_init returns null, the whole list is freed
 */

void	ft_ps_rank(t_stack **head, int lst_len)
{
	t_stack	*tmp;
	t_stack	*min_nod;
	int		rank;

	tmp = *head;
	rank = 0;
	min_nod = *head;
	while (++rank <= lst_len)
	{
		while (tmp)
		{
			if (tmp->value < min_nod->value && !tmp->rank)
				min_nod = tmp;
			tmp = tmp->next;
		}
		min_nod->rank = rank;
		min_nod = *head;
		while (rank < lst_len && min_nod->rank)
			min_nod = min_nod->next;
		tmp = *head;
	}
}

t_stack	*ft_ps_build_stack(int ac, char **av)
{
	t_stack		*stack_a;
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	stack_a = NULL;
	tmp = NULL;
	while (j < ac)
	{
		tmp = find_next_nbr(tmp, &j, av);
		if (tmp)
			stack_a = ft_ps_stack_new_addback(&stack_a, ft_atoi(tmp), i++);
		if (!stack_a)
			break ;
	}
	ft_ps_rank(&stack_a, i);
	if (stack_a)
	{
		del_print_stack(stack_a, 0);
		del_back_print(stack_a);
	}
	else
		printf("stack has an malloc issue and have been freed\n");
	return (stack_a);
}
/**********************************************************
 * if malloc does not work stack_a is freed and the loop breaks.
 * i represente the index. it is also  used in ft_ps_rank as lst_len
 */
