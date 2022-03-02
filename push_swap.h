/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:53 by lchan             #+#    #+#             */
/*   Updated: 2022/03/02 22:59:41 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include "libraries/libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				rank;
	int				index;
	struct s_stack  *previous;
	struct s_stack  *next;
}t_stack;

//push_swap_del.c
void	del_print_tab(char **tab);
void	del_print_stack(t_stack *head, int option);
void	del_back_print(t_stack *head);
void	del_print_circular_lst(t_stack *head, int opt);

//push_swap_utils.c
int		strchr_booleen(char c, char *str);

//push_swap_entrycheck.c
int		check_ascii(char **av);
char	*find_next_nbr(char *current_position, int *line, char **av);
int		check_overflow(int ac, char **av);
int		check_duplicate(int ac, char **av);
int		entry_check(int ac, char **av);

//push_swap_buildstack.c
t_stack	*ft_ps_nod_init(int value, int index);
t_stack	*ft_ps_stack_new_addback(t_stack **head, int value, int index);
t_stack *ft_ps_buildstack(int ac, char **av);
#endif
