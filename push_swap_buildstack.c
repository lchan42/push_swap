/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_buildstack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:58:49 by lchan             #+#    #+#             */
/*   Updated: 2022/02/26 01:13:42 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_free_list(t_stack **head)
{
	t_stack *tmp;
	while (*head)
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
	tmp->next = NULL;
	return (tmp);
}

t_stack *ft_ps_stack_new_addback(t_stack **head, int value, int index)
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
	}
	return (*head);
}
/*********************************************************
 * if ft_ps_nod_init returns null, the whole list is freed
 */

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
	if (stack_a)
		del_print_stack(stack_a, 0);
	else
		printf("stack had an allow issue and has been freed\n");
	return (stack_a);
}
/**********************************************************
 * if malloc does not work stack_a is freed and the loop breaks.
 */
