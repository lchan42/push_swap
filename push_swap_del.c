/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/03/03 22:20:52 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}

void	del_print_stack(t_stack *head, int option) //not used anymore
{
	if (option)
	{
		while (head)
		{
			printf("------------nod %d-----------\n", head->index);
			printf("|| 	value = %-11d||\n", head->value);
			printf("||	 rank = %-11d||\n", head->rank);
			printf("-----------------------------\n");
			head = head->next;
			if (head)
				printf("	|	|\n");
		}
	}
	else
		while (head)
		{
			printf("nod %-4d : ", head->index);
			printf("% d", head->value);
			printf("	%p\n", head);
			head = head->next;
		}
}

void	del_back_print(t_stack *head) //not used anymore
{
	t_stack	*tmp;

	tmp = head->previous;
	while (tmp != head)
	{
		printf("nod %-4d : ", tmp->index);
		printf("% d", tmp->value);
		printf("	%p\n", tmp);
		tmp = tmp->previous;
	}
	printf("nod %-4d : ", tmp->index);
	printf("% d", tmp->value);
	printf("	%p\n", tmp);
}

void	del_print_singlenod(t_stack *nod, int i, int opt)
{
	if (opt)
	{
		printf("------------nod %d-----------\n", i);
		printf("|| 	value = %-11d||\n", nod->value);
		printf("||	 rank = %-11d||\n", nod->rank);
		printf("||	 index = %-11d||\n", nod->index);
		printf("-----------------------------\n");
		if (nod->next)
			printf("	|	|\n");
	}
	else
	{
			printf("nod %-4d : ", i);
			printf("% -12d", nod->value);
			printf("rank = %4d", nod->rank);
			printf("	index = %4d", nod->index);
			printf("	%p\n", nod);
	}
}

void	del_print_circular_lst(t_stack *head, char c, int opt)
{
	t_stack	*tmp;
	int	i;

	printf("stack_%c:\n", c);
	if (head)
	{
		tmp = head->next;
		i = -1;
		del_print_singlenod(head, ++i, opt);
		while (tmp != head)
		{
			del_print_singlenod(tmp, ++i, opt);
			tmp = tmp->next;
		}
	}
	printf("\n");
//	del_print_singlenod(tmp, opt);
}
/*******************************************************
 * the last print is to make sure that the list is circular
 */

void	del_test_mvt(t_stack *stack_a, t_stack *stack_b)
{
	printf("----------------------original states---------------\n");
	del_print_circular_lst(stack_a, 'a', 0);
	del_print_circular_lst(stack_b, 'b', 0);
	printf("--------------------------sa && sb-------------------\n");
	swap(&stack_a); swap(&stack_b);
	del_print_circular_lst(stack_a, 'a', 0); del_print_circular_lst(stack_b, 'b', 0);
	printf("-------------------after pa (from b to a)-----------\n");
	push(&stack_a, &stack_b);
	del_print_circular_lst(stack_a, 'a', 0);	del_print_circular_lst(stack_b, 'b', 0);
	printf("----------------after pb (from a to b twice)--------\n");
	push(&stack_b, &stack_a);	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);	push(&stack_b, &stack_a);
	del_print_circular_lst(stack_a, 'a', 0); del_print_circular_lst(stack_b, 'b', 0);
	printf("------------------------rotation of a----------------\n");
	rotate(&stack_a, NULL);
	del_print_circular_lst(stack_a, 'a', 0); del_print_circular_lst(stack_b, 'b', 0);
	printf("------------------------rotation of b----------------\n");
	rotate(&stack_b, NULL);
	del_print_circular_lst(stack_a, 'a', 0); del_print_circular_lst(stack_b, 'b', 0);
	printf("----------------------------rr------------------------------------\n");
	rotate(&stack_b, &stack_a);
	del_print_circular_lst(stack_a, 'a', 0); del_print_circular_lst(stack_b, 'b', 0);
	printf("---------------------------rrr------------------------------------\n");
	reverse_rotate(&stack_b, &stack_a);
	del_print_circular_lst(stack_a, 'a', 0); del_print_circular_lst(stack_b, 'b', 0);
}
