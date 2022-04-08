/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:53 by lchan             #+#    #+#             */
/*   Updated: 2022/04/08 19:12:16 by lchan            ###   ########.fr       */
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

typedef struct s_ps
{
	t_stack *a;
	t_stack *b;
	t_list	*m;
}t_ps;


//push_swap_utils.c (3)
int		strchr_booleen(char c, char *str);
int		ft_ps_is_even_nbr(int nbr);
int		ps_ab_val(int n);

//ps_parsing_entrycheck.c
int		check_ascii(char **av);
char	*find_next_nbr(char *current_position, int *line, char **av);
int		check_overflow(int ac, char **av);
int		check_duplicate(int ac, char **av);
int		entry_check(int ac, char **av);

//ps_parcing_buildstack.c (5)
t_stack *ft_ps_buildstack(int ac, char **av); //there is a printf inside

//ps_mvt_a.c (4)
void	ft_ps_swap_a(t_stack **head, t_list **mvtbook);
void	ft_ps_push_a(t_stack **dst, t_stack **src, t_list **mvtbook);
void	ft_ps_rotate_a(t_stack **head, t_list **mvtbook);
void	ft_ps_reverse_a(t_stack **head, t_list **mvtbook);

//ps_mvt_b.c (4)
void	ft_ps_swap_b(t_stack **head, t_list **mvtbook);
void	ft_ps_push_b(t_stack **dst, t_stack **src, t_list **mvtbook);
void	ft_ps_rotate_b(t_stack **head, t_list **mvtbook);
void	ft_ps_reverse_b(t_stack **head, t_list **mvtbook);

//stacklen.c
int		ft_ps_stacklen(t_stack *head);
int		ft_ps_chunck_len(t_stack *head);
int		ft_ps_chunckmax_len(t_stack *head);//
int		ft_ps_full_chklen(t_stack *head, int index);//

//sorted_checker.c
int		ft_ps_sorted_checker(t_stack *head);
int		ft_ps_sorted_checker_a_n(t_stack *head, int n);//
int		ft_ps_sorted_checker_b_n(t_stack *head, int n);//
int		ft_ps_is_sorted(t_stack *head);

//sort_6_cir.c (5)
void    ft_ps_sort_a6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);

//find_pivot.c (2)
int		ft_ps_findpivot(t_stack *head);
int		ft_ps_targeted_chunckpivot(t_stack *head, int index);

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

//smart_rot_target.c (3)
void	ft_ps_targetedrot(t_stack **stack, t_list **mvtbook, t_stack *target, char *mvt);
int	ps_smrtrot_target_a(t_stack **stack, t_list **mvtbook, int target);//

// ps_free_struct.c
t_list	**ps_free_tlist_nod(t_list **m, int nxt, int nbr);
void	ps_free_tlist(t_list **m);
void	ps_free_t_stack(t_stack **a);










//smart_rot_pivot.c // -------> Warning apparently Smart rot need intern_pivot to work properly for a 
void    ft_ps_targetedrot(t_stack **stack, t_list **mvtbook, t_stack *target, char *mvt);//
int     ft_ps_smart_a_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len);//
int     ft_ps_smartrotation_a(t_stack **stack, t_list **mvtbook, int pivot);//
int     ft_ps_smart_b_bis(t_stack **tmp, t_stack **r_tmp, int pivot, int len);//
int     ft_ps_smartrotation_b(t_stack **stack, t_list **mvtbook, int pivot);//

//smart_rot_push.c//
// sub_pivot.c
void	ft_ps_pivot_mark(t_stack *head, int pivot); //not usefull in the algo. here for testing
int	ft_ps_intern_pivot_a(int chunck_len, int pivot);
int	ft_ps_intern_pivot_b(int chunck_len, int pivot);
//int	ft_ps_subpivot(t_stack *head, int pivot);
//int ft_ps_count_underpivot(t_stack *head, int pivot);
//int ft_ps_count_overpivot(t_stack *head, int pivot);
void	ft_ps_underpivotpush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	ft_ps_orgapush_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int subpivot);
void	ft_ps_recursivepush(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
//get_extrem_chunck_val.c++
int		ft_ps_min_index(t_stack *head);
int		ft_ps_max_index(t_stack *head);
//chunckorganised_push.c++
void	ft_ps_pushorganise_b(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot);
void	ft_ps_pushorganise_a(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook, int pivot);
void	ps_chkorga_pb(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	ps_chkorga_pa(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);



//push_swap_del.c
void	del_print_mvtbook(t_list *mvtbook);
void	del_print_circular_lst(t_stack *head, char c, int opt);
void	del_test_mvt(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_sort_b3_cir(t_stack **stack_a, t_stack **stack_b, t_list **mvtbook);
void	del_test_sort_a6_cir(t_stack **stack_a, t_stack ** stack_b, t_list **mvtbook);

#endif
