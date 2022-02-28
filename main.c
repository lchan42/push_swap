/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:45:08 by lchan             #+#    #+#             */
/*   Updated: 2022/02/28 23:39:56 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int ac, char **av)
{
	t_stack	*stack;
        if (!entry_check(--ac, (++av)))
        {
                printf("ENTRY ERROR\n");
                return (0);
        }
        else
                printf(">>> entry is ok <<<\n");
		stack = ft_ps_buildstack(ac, av);
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
 * moving functions; 
 * garbage colector ?;
 * cd /Users/lchan/Downloads
 * echo -n "" | ./checker_Mac "- 1" 2 3 "7  +5 6" 8
 * echo "rra" | ./checker_Mac "2 3" "4 5 6 1"
 * gcc -g3 -fsanitize=address *.c libraries/libft/libft.a
 * */
