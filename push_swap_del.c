/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/02/26 01:12:34 by lchan            ###   ########.fr       */
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

void	del_print_stack(t_stack *head, int option)
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
			printf("% d\n", head->value);
			head = head->next;
		}
}
