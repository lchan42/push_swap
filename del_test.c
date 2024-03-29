/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:59 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 21:36:11 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}
/*******************************************************
 * the last print is to make sure that the list is circular
 */

void	del_print_chunck(t_stack *s, int index)
{
	int	nod_index;
	int	stack_len;
	int	chk_len;

	nod_index = 0;
	stack_len = ft_ps_stacklen(s);
	chk_len = ft_ps_chunck_len(s);
	if (stack_len != chk_len)
	{
		while (s->index == index && stack_len--)
			s = s->next;
		while (s->index != index && stack_len--)
			s = s->next;
	}
	else
		chk_len = ft_ps_chunck_len(s);
	while (s->index == index && chk_len--)
	{
		del_print_singlenod(s, nod_index++, 0);
		s = s->next;
	}
}

void	del_print_mvtbook(t_list *head)
{
	int	count;

	count = 0;
	while (head)
	{
		printf("%s", (char *)head->content);
		count++;
		if (head->next)
			printf(" ");
		head = head->next;
	}
	printf("\ncount = %d\n", count);
}

void	del_test_mvt(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	printf("----------------------original states---------------\n");
	del_print_circular_lst(*stack_a, 'a', 0);
	del_print_circular_lst(*stack_b, 'b', 0);
	printf("-------------------after pa (from b to a)-----------\n");
	ft_ps_push_a(stack_a, stack_b, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0);	del_print_circular_lst(*stack_b, 'b', 0);
	printf("----------------after pb (from a to b twice)--------\n");
	ft_ps_push_b(stack_b, stack_a, mvtbook); ft_ps_push_b(stack_b, stack_a, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0);	del_print_circular_lst(*stack_b, 'b', 0);
	printf("--------------------------sa && sb-------------------\n");
	ft_ps_swap_a(stack_a, mvtbook); ft_ps_swap_b(stack_b, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("------------------------rotation of a----------------\n");
	ft_ps_rotate_a(stack_a, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("------------------------rotation of a----------------\n");
	ft_ps_reverse_a(stack_a, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("----------------------------rr------------------------------------\n");
	ft_ps_rotate_a(stack_a, mvtbook); ft_ps_rotate_b(stack_b, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("---------------------------rrr------------------------------------\n");
	ft_ps_reverse_a(stack_a, mvtbook); ft_ps_reverse_b(stack_b, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	del_print_mvtbook(*mvtbook);
}

void	del_test_sort_a6_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	printf("----------------------original states---------------\n");
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("-------------------after sorting stack a ----------------\n");
	ft_ps_sort_a6_cir(stack_a, stack_b, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	del_print_mvtbook(*mvtbook);
}

/*  --> test was not conclueent for under over pivot technique.
void	del_test_underover_pivot(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int	chunck_pivot = ft_ps_chunckpivot(*stack_a);

	printf("----------------------original states---------------\n");
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("pivot = %d\n", chunck_pivot);
	printf("subpivot = %d\n", ft_ps_subpivot(*stack_a, chunck_pivot));
	printf("over pivot = %d\n", ft_ps_count_overpivot(*stack_a, chunck_pivot));
	printf("under pivot = %d\n", ft_ps_count_underpivot(*stack_a, chunck_pivot));
	ft_ps_pivot_mark(*stack_a, chunck_pivot);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	del_print_mvtbook(*mvtbook);
}

void	del_test_underpivotpush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{// we saw that this algo is not efficient for 	
	int	chunck_pivot = ft_ps_chunckpivot(*stack_a);

	printf("----------------------original states---------------\n");
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("-------------------after sorting stack a ----------------\n");
	printf("pivot = %d\n", chunck_pivot);
	printf("subpivot = %d\n", ft_ps_subpivot(*stack_a, chunck_pivot));
	printf("over pivot = %d\n", ft_ps_count_overpivot(*stack_a, chunck_pivot));
	printf("under pivot = %d\n", ft_ps_count_underpivot(*stack_a, chunck_pivot));
//	ft_ps_underpivotpush_b(stack_a, stack_b, mvtbook);	
	ft_ps_recursivepush(stack_a, stack_b, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	del_print_mvtbook(*mvtbook);
}

void	del_test_sort_a10_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook)
{
	printf("----------------------original states---------------\n");
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	printf("-------------------after sorting stack a ----------------\n");
	ft_ps_sort_a10_cir(stack_a, stack_b, mvtbook);
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	del_print_mvtbook(*mvtbook);
}
*/
/* this function was to test the old algorithm. 
void	del_test_pushorganise_b(t_stack**stack_a, t_stack **stack_b, t_list **mvtbook)
{
	int pivot;
	printf("----------------------original states---------------\n");
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	
	ft_ps_juggle(stack_a, stack_b, mvtbook);
	
	printf("-------------------after sorting stack a ----------------\n");
	del_print_circular_lst(*stack_a, 'a', 0); del_print_circular_lst(*stack_b, 'b', 0);
	del_print_mvtbook(*mvtbook);
}*/

/*****************
 * pa = from b to a. a is the destination
 * */
