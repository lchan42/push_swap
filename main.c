/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:45:08 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 18:09:19 by lchan            ###   ########.fr       */
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
	
//	del_test_sort_a3(&a, &b, &m);
if (ft_ps_stacklen(a) <= 6)
	del_test_sort_a6_cir(&a, &b, &m);
else 
{
	del_print_circular_lst(a, 'a', 0);
	del_print_circular_lst(b, 'b', 0);
		if (!ps_longsub_sort(&a, &b, &m))
			return (0);
	del_print_circular_lst(a, 'a', 0);
	del_print_circular_lst(b, 'b', 0);
	ps_opt_mvtbook(m);
	del_print_mvtbook(m);
}
ps_free_tlist(&m);
ps_free_t_stack(&a);
ps_free_t_stack(&b);

}
