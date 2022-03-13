/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_buildstack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:58:49 by lchan             #+#    #+#             */
/*   Updated: 2022/03/13 21:02:04 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_free_list(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head->next;
		printf("free : %p\n", head);
		free(head);
		head = tmp;
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
		{
			ft_ps_free_list(*head);
			return (NULL);
		}
		tmp->next->previous = tmp;
		(*head)->previous = tmp->next;
	}
	return (*head);
}
/*********************************************************
 * if ft_ps_nod_init returns null, the whole list is freed
 * (*head)->previous = is set, however tmp->next->next is still null. Will be set at the end ft_ps_buildstack
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

t_stack	*ft_ps_buildstack(int ac, char **av)
{
	t_stack		*stack;
	char		*tmp;
	int			i;
	int			j;

	if (!av[1])
		return (NULL);
	i = 0;
	j = 0;
	stack = NULL;
	tmp = NULL;
	while (j < ac)
	{
		tmp = find_next_nbr(tmp, &j, av);
		if (tmp)
			stack = ft_ps_stack_new_addback(&stack, ft_atoi(tmp), i++);
		if (!stack)
			break ;
	}
	ft_ps_rank(&stack, i);
	if (stack)
		stack->previous->next = stack;
	else
		printf("stack has an malloc issue and have been freed\n");
	return (stack);
}
/**********************************************************
 * if malloc does not work stack is freed and the loop breaks.
 * i represente the index. it is also  used in ft_ps_rank as lst_len
 * the list is made circular at the end (easier that way)
 */
