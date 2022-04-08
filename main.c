/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:45:08 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 15:03:00 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*m;
	t_ps	c;

	if (ac < 2)
		return (0);
	if (!entry_check(--ac, (++av)))
	{
		printf("ENTRY ERROR\n");
		return (0);
	}
	else
		printf(">>> entry is ok <<<\n");
	a = ft_ps_buildstack(ac, av);
	b = NULL;
	m = NULL;
	c.a = a;
	c.b = b;
	c.m = m;
	
//del_test_sort_b6_cir(&a, &b, &m);
//del_test_sort_a6_cir(&a, &b, &m);

//del_test_ft_ps_sort(&a, &b, &m);
//ps_longest_seq(a, 1);
del_print_circular_lst(a, 'a', 0);
del_print_circular_lst(b, 'b', 0);
if (!ps_longsub_sort(&a, &b, &m))
	return (0);
del_print_circular_lst(a, 'a', 0);
del_print_circular_lst(b, 'b', 0);
del_print_mvtbook(m);
ps_opt_mvtbook(m);
del_print_mvtbook(m);
ps_free_tlist(&m);
ps_free_t_stack(&a);
ps_free_t_stack(&b);
//del_print_circular_lst(a, 'a', 0);
//del_print_circular_lst(b, 'b', 0);
//del_print_mvtbook(m);

//del_test_findtarget(a, b->previous);
//del_test_underpivotpush_b(&a, &b, &m);
//	ft_ps_juggle(&a, &b, &m);
//	del_test_pushorganise_b(&a, &b, &m);

//	del_test_sort_a3(&a, &b, &m);
//	del_test_sort_a10_cir(&a, &b, &m);
//	del_test_sort_b3_cir(&a, &b, &m);
//	del_test_underover_pivot(&a, &b, &m);

	
//del_test_underpivotpush_b(&a, &b, &m);

}
/**********************************************
 * --ac coz we do not care about the first entry.
 * ++av for the same reason.
 */

/* TO DO LIST
 * check school corrector; DOWN
 * check entry; DOWN
 * build stack rank; DOWN 28/02;
 * bedirectional chainlst; DOWN 28/02;
 * moving functions;-->test funtions; 
 * check what happens to the circular function if there only one element. i
 * 		Apparently it should still be circular (head->next = head)
 * put all the possibilities of a combinaison of words into a tab, I have to think in term of factoral

 * cd /Users/lchan/Downloads
 * echo -n "" | ./checker_Mac "- 1" 2 3 "7  +5 6" 8
 * echo "rra" | ./checker_Mac "2 3" "4 5 6 1"
 * gcc -g3 -fsanitize=address *.c libraries/libft/libft.a
 * */
