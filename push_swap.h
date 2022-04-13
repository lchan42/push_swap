
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:53 by lchan             #+#    #+#             */
/*   Updated: 2022/04/13 15:53:39 by lchan            ###   ########.fr       */
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
# include "./libraries/libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				rank;
	int				index;
	struct s_stack  *previous;
	struct s_stack  *next;
}t_stack;

typedef struct s_ps
{
	t_stack *a;
	t_stack *b;
	t_list	*m;
}sk;

enum exit_code
{
//	ARG_NBR_ERROR = 10,
	ASCII_ERROR = 10,
	OVERFLOW_ERROR,
	DUPLICATE_ERROR,
	BUILDSTACK_ERROR,
	MVTBOOK_ERROR,
};

//ps_utils_general.c (3)
int		strchr_booleen(char c, char *str);
int		ps_count_digit(char *tmp, int count);
char	*find_next_nbr(char *current_position, int *line, char **av);
int		ft_ps_is_even_nbr(int nbr);
int		ps_ab_val(int n);

//ps_utils_stacklen.c (2)
int		ft_ps_stacklen(t_stack *head);
int		ft_ps_chunck_len(t_stack *head);

//ps_parsing_entrycheck.c (5)
int		ps_count_element(int ac, char **av);
int		entry_check(int ac, char **av);

//ps_parcing_buildstack.c (4)
t_stack *ft_ps_buildstack(int ac, char **av);

//ps_mvt_a.c (4)
void	ft_ps_swap_a(t_stack **a, t_list **m);
void	ft_ps_push_a(t_stack **dst, t_stack **src, t_list **mvtbook);
void	ft_ps_rotate_a(t_stack **a, t_list **m);
void	ft_ps_reverse_a(t_stack **a, t_list **m);

//ps_mvt_b.c (4)
void	ft_ps_swap_b(t_stack **head, t_list **mvtbook);
void	ft_ps_push_b(t_stack **dst, t_stack **src, t_list **mvtbook);
void	ft_ps_rotate_b(t_stack **head, t_list **mvtbook);
void	ft_ps_reverse_b(t_stack **head, t_list **mvtbook);

//ps_sorted_checker.c (2)
int		ft_ps_sorted_checker(t_stack *head);
int		ft_ps_is_sorted(t_stack *head);

//ps_sort_6_cir.c (5)
void    ft_ps_sort_a6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);

//ps_sort_find_pivot.c (2)
int		ft_ps_findpivot(t_stack *head);
int		ft_ps_intern_pivot_a(int chunck_len, int pivot);

//ps_longest_sub_utils.c /(5)
void	ps_tab_free(int **tab);
int		**ps_tab_init(int len);
int		**ps_tab_create(t_stack *stk, int len);
int 	ps_tab_len(int *tab);
int		ps_dtab_len(int **tab);

void	ps_printtab(int **tab); //gonna have to delete that eventually;
void	ps_printseq(int *tab, int np); // gonna have to delete that eventually;
void	ps_printcost(int **tab); //gonna have to delete that afterwards;

//ps_longest_sub_get.c (5)
int	*ps_longest_seq(t_stack *stk, int opt);

//ps_longest_sub_algo.c (5)
int	ps_longsub_sort(t_stack **a, t_stack **b, t_list **m);

//ps_cost_tab_get.c (5)
int	**ps_cost_tab(t_stack *dst, t_stack *src);

//ps_opti_mvtbook.c (5)
void	ps_opt_mvtbook(t_list *m);

//ps_opti_cost_tab.c (2)
int	**ps_opt_costtab(int	**tab);

//ps_smart_rot_target.c (3)
void	ft_ps_targetedrot(t_stack **stack, t_list **m, t_stack *targ, char *mvt);
int		ps_smrtrot_target_a(t_stack **stack, t_list **m, int targ);

//ps_smart_rot_pivot.c (4) 
int     ft_ps_smartrotation_a(t_stack **stack, t_list **m, int pivot);
int     ft_ps_smartrotation_b(t_stack **stack, t_list **m, int pivot);

// ps_free_struct.c (4)
void	ps_emergencyfree_list(t_stack *head);
t_list	**ps_free_tlist_nod(t_list **m, int nxt, int nbr);
void	ps_free_tlist(t_list **m);
void	ps_free_t_stack(t_stack **a);
void	ps_free_env(t_stack **a, t_stack **b, t_list **m);

//ps_print_mvt.c
void	ps_print_mvt(t_list *m);

//ps_exit_error.c
void	ps_exit_error(int exitcode);
void	ps_exit_error_free(t_stack **a, t_stack **b, t_list **m, int exitcode);

//push_swap_del.c
void	del_print_mvtbook(t_list *mvtbook);
void	del_print_circular_lst(t_stack *head, char c, int opt);
void	del_test_mvt(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_sort_b3_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_sort_a6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);

#endif
