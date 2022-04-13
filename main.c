/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:45:08 by lchan             #+#    #+#             */
/*   Updated: 2022/04/13 15:53:43 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "./libraries/libft/libft.h"

int     main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*m;

	if (!entry_check(ac, (av)))
		return (0);
	a = ft_ps_buildstack(--ac, ++av);
	b = NULL;
	m = NULL;

//	del_print_circular_lst(a, 'a', 0);
//	del_print_circular_lst(b, 'b', 0);
	if (ft_ps_stacklen(a) <= 6)
		ft_ps_sort_a6_cir(&a, &b, &m);
	else 
	{
		if (!ps_longsub_sort(&a, &b, &m))
			return (0);
		ps_opt_mvtbook(m);
	}
//	del_print_circular_lst(a, 'a', 0);
//	del_print_circular_lst(b, 'b', 0);
//	del_print_mvtbook(m);
	ps_print_mvt(m);
	ps_free_env(&a, &b, &m);
//	ps_free_tlist(&m);
//	ps_free_t_stack(&a);
//	ps_free_t_stack(&b);
}

/*
int     main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*m;

	if (ac < 2)
		return (0);
	entry_check(--ac, (++av))
		return (0);
	else
		printf(">>> entry is ok <<<\n");
	a = ft_ps_buildstack(ac, av);
	b = NULL;
	m = NULL;
	
	del_print_circular_lst(a, 'a', 0);
	del_print_circular_lst(b, 'b', 0);
	if (ft_ps_stacklen(a) <= 6)
		ft_ps_sort_a6_cir(&a, &b, &m);
	else 
	{
		if (!ps_longsub_sort(&a, &b, &m))
			return (0);
		ps_opt_mvtbook(m);
	}
	del_print_circular_lst(a, 'a', 0);
	del_print_circular_lst(b, 'b', 0);
	del_print_mvtbook(m);
	ps_free_tlist(&m);
	ps_free_t_stack(&a);
	ps_free_t_stack(&b);
}*/
