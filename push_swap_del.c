/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/02/28 23:33:36 by lchan            ###   ########.fr       */
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

void	del_print_singlenod(t_stack *nod, int opt)
{
	if (opt)
	{
		printf("------------nod %d-----------\n", nod->index);
		printf("|| 	value = %-11d||\n", nod->value);
		printf("||	 rank = %-11d||\n", nod->rank);
		printf("-----------------------------\n");
		if (nod->next)
			printf("	|	|\n");
	}
	else
	{
			printf("nod %-4d : ", nod->index);
			printf("% -12d", nod->value);
			printf("rank = %4d", nod->rank);
			printf("	%p\n", nod);
	}
}

void	del_print_circular_lst(t_stack *head, int opt)
{
	t_stack	*tmp;

	tmp = head->next;
	del_print_singlenod(head, opt);
	while (tmp != head)
	{
		del_print_singlenod(tmp, opt);
		tmp = tmp->next;
	}
//	del_print_singlenod(tmp, opt);
}
/*******************************************************
 * the last print is to make sure that the list is circular
 */
